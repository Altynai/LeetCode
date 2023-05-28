template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxIncreasingCells(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<array<int, 3>> v;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        v.push_back({a[i][j], i, j});
      }
    }
    sort(v.begin(), v.end());

    int ans = 1;
    vector<vector<int>> dp(n, vector<int>(m, 1));
    vector<int> row_max(n, 0), col_max(m, 0);
    for (int j = v.size() - 1; j >= 0;) {
      int i = j;
      while (i >= 0 and v[i][0] == v[j][0]) {
        int r = v[i][1], c = v[i][2];
        int len = max(row_max[r], col_max[c]) + 1;
        umax(dp[r][c], len);
        umax(ans, len);
        i--;
      }

      i = j;
      while (i >= 0 and v[i][0] == v[j][0]) {
        int r = v[i][1], c = v[i][2];
        umax(row_max[r], dp[r][c]);
        umax(col_max[c], dp[r][c]);
        i--;
      }

      j = i;
    }
    return ans;
  }
};
