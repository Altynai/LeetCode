template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maximumAmount(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(3, INT_MIN)));

    dp[0][0][0] = a[0][0];
    if (a[0][0] < 0)
      dp[0][0][1] = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 3; k++) {
          if (dp[i][j][k] == INT_MIN)
            continue;

          // right
          if (j + 1 < m) {
            // do nothing
            umax(dp[i][j + 1][k], dp[i][j][k] + a[i][j + 1]);
            // use 1 time ability
            if (a[i][j + 1] < 0 and k <= 1)
              umax(dp[i][j + 1][k + 1], dp[i][j][k]);
          }

          // down
          if (i + 1 < n) {
            // do nothing
            umax(dp[i + 1][j][k], dp[i][j][k] + a[i + 1][j]);
            // use 1 time ability
            if (a[i + 1][j] < 0 and k <= 1)
              umax(dp[i + 1][j][k + 1], dp[i][j][k]);
          }
        }
      }
    }

    return *max_element(dp[n - 1][m - 1].begin(), dp[n - 1][m - 1].end());
  }
};
