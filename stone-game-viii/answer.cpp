class Solution {
public:
  int stoneGameVIII(vector<int> &s) {
    int n = s.size();
    for (int i = 1; i < n; i++)
      s[i] += s[i - 1];

    vector<int> dp(n, 0);
    dp[n - 2] = s[n - 1];
    for (int i = n - 3; i >= 0; i--) {
      dp[i] = max(dp[i + 1], s[i + 1] - dp[i + 1]);
    }
    return dp[0];
  }
};
