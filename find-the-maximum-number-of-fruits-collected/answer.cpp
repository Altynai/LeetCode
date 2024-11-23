template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxCollectedFruits(vector<vector<int>> &a) {
    /*
    A x          B
    x x        x x x

      x
    C x
      x

    we can at most select 3 * (n - 1) - 2 cells
    but for A, he has to choose the path (0, 0), (1, 1), (2, 2), ... , (n - 1, n
    - 1)

    for B, as he always moves down to the next row, if we have L times of
    choosing left then we must also choose L times for right and L * 2 <= n - 2

    so it implies that B will never cross the path for A, same case for C
    */

    int n = a.size(), ans = 0;

    // A
    for (int i = 0; i < n; i++) {
      ans += a[i][i];
      a[i][i] = 0; // avoid re-count
    }

    // B
    vector<vector<int>> f(n, vector<int>(n, 0));
    f[0][n - 1] = a[0][n - 1];
    for (int i = 1; i < n; i++) {
      int l = n - i - 1; // left most possible position
      umax(l, i);        // but we should be able to go back to (n - 1, n - 1)

      for (int j = l; j < n; j++) {
        umax(f[i][j], f[i - 1][j]);
        if (j > 0)
          umax(f[i][j], f[i - 1][j - 1]);
        if (j + 1 < n)
          umax(f[i][j], f[i - 1][j + 1]);
        // if (i < j)
        f[i][j] += a[i][j];
      }
    }
    ans += f[n - 1][n - 1];

    // C
    vector<vector<int>> g(n, vector<int>(n, 0));
    g[n - 1][0] = a[n - 1][0];
    for (int j = 1; j < n; j++) {
      int up = n - j - 1; // up most possible position
      umax(up, j);        // but we should be able to go back to (n - 1, n - 1)

      for (int i = up; i < n; i++) {
        umax(g[i][j], g[i][j - 1]);
        if (i > 0)
          umax(g[i][j], g[i - 1][j - 1]);
        if (i + 1 < n)
          umax(g[i][j], g[i + 1][j - 1]);
        g[i][j] += a[i][j];
      }
    }
    ans += g[n - 1][n - 1];

    return ans;
  }
};
