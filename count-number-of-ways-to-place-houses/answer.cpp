const int MOD = 1e9 + 7;

class Solution {
public:
  int countHousePlacements(int n) {
    vector<int> dp = {1, 1};
    for (int i = 1; i < n; i++) {
      vector<int> ndp(2, 0);
      ndp[0] = (dp[0] + dp[1]) % MOD;
      ndp[1] = dp[0] % MOD;
      dp = ndp;
    }
    int ans = (dp[0] + dp[1]) % MOD;
    return 1LL * ans * ans % MOD;
  }
};
