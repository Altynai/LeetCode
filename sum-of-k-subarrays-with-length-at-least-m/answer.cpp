template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxSum(vector<int> &a, int k, int m) {
    // dp[i][j]: maximum sum of j subarrays from [0 ... i]
    // dp[i][j] = max(dp[x][j - 1] + sum[i] - sum[x])
    // x <= i - m

    int n = a.size();
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + a[i - 1];

    vector<int> dp(n + 1), prev_best(n + 1, 0);
    for (int i = 1; i <= n; i++)
      umax(prev_best[i], max(prev_best[i - 1], -sum[i]));

    for (int j = 1; j <= k; j++) {
      dp.assign(n + 1, INT_MIN);
      for (int i = 1; i <= n; i++) {
        umax(dp[i], dp[i - 1]);
        int x = i - m;
        if (x >= 0 and prev_best[x] != INT_MIN)
          umax(dp[i], prev_best[x] + sum[i]);
      }

      // update prev_best
      prev_best.assign(n + 1, INT_MIN);
      for (int i = 0; i <= n; i++) {
        if (dp[i] == INT_MIN)
          continue;

        umax(prev_best[i], dp[i] - sum[i]);
        if (i > 0)
          umax(prev_best[i], prev_best[i - 1]);
      }
    }
    return dp[n];
  }
};
