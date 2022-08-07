class Solution {
public:
  bool validPartition(vector<int> &a) {
    int n = a.size();
    vector<bool> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      if (i >= 2 and a[i - 1] == a[i - 2])
        dp[i] = dp[i] || dp[i - 2];
      if (i >= 3 and a[i - 1] == a[i - 2] and a[i - 2] == a[i - 3])
        dp[i] = dp[i] || dp[i - 3];
      if (i >= 3 and a[i - 1] - 1 == a[i - 2] and a[i - 2] - 1 == a[i - 3])
        dp[i] = dp[i] || dp[i - 3];
    }
    return dp[n];
  }
};
