template <class T> bool umin(T &a, const T b) { return a > b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long minCost(int n, int m, vector<vector<int>> &waitCost) {
    vector<vector<int64>> dp(n, vector<int64>(m, LLONG_MAX));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        // down
        if (i + 1 < n)
          umin(dp[i + 1][j],
               dp[i][j] + 1LL * (i + 2) * (j + 1) + waitCost[i + 1][j]);
        // right
        if (j + 1 < m)
          umin(dp[i][j + 1],
               dp[i][j] + 1LL * (i + 1) * (j + 2) + waitCost[i][j + 1]);
      }
    }
    return dp[n - 1][m - 1] - waitCost[n - 1][m - 1];
  }
};
