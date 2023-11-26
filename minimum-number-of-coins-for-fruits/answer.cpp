class Solution {
public:
  int minimumCoins(vector<int> &p) {
    int n = p.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = p[n - 1];
    for (int i = n - 1; i >= 1; i--) {
      if (i + i >= n)
        dp[i] = min(dp[i], p[i - 1]);
      else {
        int best = INT_MAX;
        for (int j = i + 1; j <= min(n, i + i + 1); j++) {
          best = min(best, dp[j]);
        }
        dp[i] = min(dp[i], best + p[i - 1]);
      }
    }
    return dp[1];
  }
};
