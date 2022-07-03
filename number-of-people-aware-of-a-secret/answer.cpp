const int MOD = 1e9 + 7;

int add(int x, int y) {
  y = (y + MOD) % MOD;
  return (x + y) % MOD;
}

class Solution {
public:
  int peopleAwareOfSecret(int n, int delay, int forget) {
    vector<int> dp(n + 2, 0);
    dp[1] = dp[delay + 1] = 1;
    dp[forget + 1] = -2;

    for (int i = 2; i <= n; i++) {
      dp[i] = add(dp[i], dp[i - 1]);
      if (delay + i <= n)
        dp[delay + i] = add(dp[delay + i], dp[i]);
      if (forget + i <= n)
        dp[forget + i] = add(dp[forget + i], -dp[i]);
    }
    return dp[n];
  }
};
