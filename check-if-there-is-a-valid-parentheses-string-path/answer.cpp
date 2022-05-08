const int N = 101;
bool dp[N][N][N << 1];

class Solution {
public:
  bool hasValidPath(vector<vector<char>> &a) {
    int n = a.size(), m = a[0].size();
    int p = n + m - 1;

    memset(dp, 0, sizeof(dp));
    if (a[0][0] == '(')
      dp[0][0][1] = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == 0 and j == 0)
          continue;

        for (int k = 0; k <= p; k++) {
          if (a[i][j] == '(') {
            if (i and k and dp[i - 1][j][k - 1])
              dp[i][j][k] = 1;
            if (j and k and dp[i][j - 1][k - 1])
              dp[i][j][k] = 1;
          } else {
            if (i and k and dp[i - 1][j][k])
              dp[i][j][k - 1] = 1;
            if (j and k and dp[i][j - 1][k])
              dp[i][j][k - 1] = 1;
          }
        }
      }
    }
    return dp[n - 1][m - 1][0];
  }
};
