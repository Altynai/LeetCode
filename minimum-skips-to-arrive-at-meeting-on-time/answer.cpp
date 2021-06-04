// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int minSkips(vector<int> &dist, int speed, int hoursBefore) {
    // dp[i][j]: 前i个，用了j次，最小的结束的 hour 时间
    // dp[i][j] = min(dp[i - k][j - 1] + sum[i-k ... k] / speed + 1)
    auto _ceil = [&](int val) { return (val + speed - 1) / speed * speed; };

    int n = dist.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= i; j++) {
        // wait and rest
        if (dp[i - 1][j] != INT_MAX)
          umin(dp[i][j], _ceil(dp[i - 1][j] + dist[i - 1]));
        // skip the rest
        if (j && dp[i - 1][j - 1] != INT_MAX)
          umin(dp[i][j], dp[i - 1][j - 1] + dist[i - 1]);
      }
    }
    for (int j = 0; j <= n; j++) {
      if (1LL * dp[n][j] <= 1LL * hoursBefore * speed) {
        return j;
      }
    }
    return -1;
  }
};
