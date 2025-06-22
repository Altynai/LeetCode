class Solution {
public:
  vector<int> findCoins(vector<int> &dp) {
    int n = dp.size();
    dp.insert(dp.begin(), 1);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if (dp[i] > 1)
        return {};
      if (dp[i] == 0)
        continue;
      for (int j = n; j >= i; j--)
        dp[j] -= dp[j - i];
      if (dp[i] != 0)
        return {};
      ans.push_back(i);
    }
    return ans;
  }
};
