class Solution {
public:
  int firstDayBeenInAllRooms(vector<int> &nextVisit) {
    const int MOD = 1e9 + 7;

    int n = nextVisit.size();
    vector<int> dp(n, 0), sum(n, 0);

    sum[0] = dp[0] = 1;
    for (int i = 1; i < n - 1; i++) {
      int j = nextVisit[i];
      int s = (j == 0 ? sum[i - 1] : sum[i - 1] - sum[j - 1]);
      dp[i] = (dp[i] + 1) % MOD; // go back
      dp[i] = (1LL * dp[i] + s + MOD + i - j) % MOD;
      sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }
    return (sum[n - 2] + n - 1) % MOD;
  }
};
