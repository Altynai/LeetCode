class Solution {
public:
  int maxScore(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        dp[i][j] = a[i][j];
        if (i == n - 1 and j == m - 1)
          continue;

        if (i + 1 < n)
          dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        if (j + 1 < m)
          dp[i][j] = max(dp[i][j], dp[i][j + 1]);
      }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == n - 1 and j == m - 1)
          continue;
        if (i + 1 < n)
          ans = max(ans, dp[i + 1][j] - a[i][j]);
        if (j + 1 < m)
          ans = max(ans, dp[i][j + 1] - a[i][j]);
      }
    }
    return ans;
  }
};
