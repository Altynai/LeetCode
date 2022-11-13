const int MOD = 1e9 + 7;

class Solution {
public:
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= high; i++) {
      if (i >= zero)
        dp[i] = (dp[i] + dp[i - zero]) % MOD;
      if (i >= one)
        dp[i] = (dp[i] + dp[i - one]) % MOD;
    }

    int ans = 0;
    for (int i = low; i <= high; i++)
      ans = (ans + dp[i]) % MOD;
    return ans;
  }
};
