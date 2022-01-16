class Solution {
public:
  long long mostPoints(vector<vector<int>> &q) {
    int n = q.size();
    vector<long long> dp(n, 0);

    for (int i = n - 1; i >= 0; i--) {
      int point = q[i][0], m = q[i][1];
      int j = i + m + 1;
      long long best = 0;
      if (j < n)
        best = max(best, dp[j]);
      best += point;

      dp[i] = max(dp[i], best);
      if (i + 1 < n)
        dp[i] = max(dp[i], dp[i + 1]);
    }
    return dp[0];
  }
};
