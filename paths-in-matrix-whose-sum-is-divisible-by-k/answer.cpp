const int MOD = 1e9 + 7;

class Solution {
public:
  int numberOfPaths(vector<vector<int>> &a, int k) {
    int n = a.size(), m = a[0].size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(m, vector<int>(k, 0)));
    dp[0][0][a[0][0] % k] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 and j == 0)
          continue;

        int w = a[i][j] % k;
        for (int x = 0; x < k; x++) {
          int y = (x - w + k) % k;
          if (j > 0)
            dp[i][j][x] = (dp[i][j][x] + dp[i][j - 1][y]) % MOD;
          if (i > 0)
            dp[i][j][x] = (dp[i][j][x] + dp[i - 1][j][y]) % MOD;
        }
      }
    }
    return dp[n - 1][m - 1][0];
  }
};
