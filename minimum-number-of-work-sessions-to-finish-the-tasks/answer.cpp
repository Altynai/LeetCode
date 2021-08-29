class Solution {
public:
  int minSessions(vector<int> &tasks, int sessionTime) {
    int n = tasks.size();
    vector<int> sum(1 << n, 0);
    for (int i = 1; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) {
        if (i & (1 << j)) {
          sum[i] += tasks[j];
        }
      }
    }

    vector<int> dp(1 << n, INT_MAX);
    function<int(int)> dfs = [&](int mask) -> int {
      if (dp[mask] != INT_MAX)
        return dp[mask];
      if (mask == 0)
        return dp[0] = 0;

      for (int i = mask; i > 0; i = (i - 1) & mask) {
        if (sum[i] <= sessionTime)
          dp[mask] = min(dp[mask], dfs(mask ^ i) + 1);
      }
      return dp[mask];
    };

    return dfs((1 << n) - 1);
  }
};
