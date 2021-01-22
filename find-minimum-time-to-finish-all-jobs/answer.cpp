class Solution {
public:
  int minimumTimeRequired(vector<int> &jobs, int k) {
    int n = jobs.size();

    int dp[k + 1][1 << n];
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j < (1 << n); j++)
        dp[i][j] = INT_MAX;
    }

    vector<int> sum(1 << n, 0);
    for (int j = 0; j < (1 << n); j++) {
      for (int i = 0; i < n; i++) {
        if ((j >> i) & 1)
          sum[j] += jobs[i];
      }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
      for (int j = 0; j < (1 << n); j++) {
        if (dp[i - 1][j] == INT_MAX)
          continue;

        for (int mask = 0; mask < (1 << n); mask++) {
          if (j & mask)
            continue;
          dp[i][j | mask] = min(dp[i][j | mask], max(dp[i - 1][j], sum[mask]));
        }
      }
    }
    return dp[k][(1 << n) - 1];
  }
};
