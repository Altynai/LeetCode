template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }
template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

const int N = 31;

class Solution {
public:
  int minimumSum(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();

    // pre-calculation
    vector<vector<int>> row(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> col(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        row[i][j] = row[i][j - 1] + a[i - 1][j - 1];
      }
    }
    for (int j = 1; j <= m; j++) {
      for (int i = 1; i <= n; i++) {
        col[i][j] = col[i - 1][j] + a[i - 1][j - 1];
      }
    }

    // find the minimal rectangle to cover all 1's in this area
    auto GetArea = [&](int r0, int c0, int r1, int c1) -> int {
      int rmin = n, rmax = -1;
      int cmin = m, cmax = -1;
      for (int i = r0; i <= r1; i++) {
        int val = row[i][c1] - row[i][c0 - 1];
        if (val > 0)
          umin(rmin, i), umax(rmax, i);
      }
      if (rmax == -1)
        return 0;

      for (int j = c0; j <= c1; j++) {
        int val = col[rmax][j] - col[rmin - 1][j];
        if (val > 0)
          umin(cmin, j), umax(cmax, j);
      }
      return (rmax - rmin + 1) * (cmax - cmin + 1);
    };

    // minimal area with one cut
    auto MinArea = [&](int r0, int c0, int r1, int c1) -> int {
      int res = INT_MAX;
      // vertical cut
      if (c0 < c1) {
        for (int j = c0; j < c1; j++)
          umin(res, GetArea(r0, c0, r1, j) + GetArea(r0, j + 1, r1, c1));
      }
      // horizontal cut
      if (r0 < r1) {
        for (int i = r0; i < r1; i++)
          umin(res, GetArea(r0, c0, i, c1) + GetArea(i + 1, c0, r1, c1));
      }
      return res;
    };

    int ans = n * m;
    // first cut is vertical
    for (int j = 1; j < m; j++) {
      // choose the left part
      int res = GetArea(1, 1, n, j);
      res += MinArea(1, j + 1, n, m);
      umin(ans, res);

      // choose the right part
      res = GetArea(1, j + 1, n, m);
      res += MinArea(1, 1, n, j);
      umin(ans, res);
    }

    // first cut is horizontal
    for (int i = 1; i < n; i++) {
      // choose the up part
      int res = GetArea(1, 1, i, m);
      res += MinArea(i + 1, 1, n, m);
      umin(ans, res);

      // choose the bottom part
      res = GetArea(i, 1, n, m);
      res += MinArea(1, 1, i, m);
      umin(ans, res);
    }

    return ans;
  }
};
