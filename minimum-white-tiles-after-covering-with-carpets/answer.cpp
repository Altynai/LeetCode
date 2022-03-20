template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int minimumWhiteTiles(string s, int m, int len) {
    int n = s.size();
    if (m * len >= n)
      return 0;

    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
      sum[i] = sum[i - 1] + (s[i - 1] == '1');

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int ans = 0;
    for (int j = 0; j <= m; j++) {
      int cur = 0, pre = 0;
      for (int i = 1; i <= n; i++) {
        // do not cover s[i - 1]
        // dp[i][j] = max(dp[k][j]) k <= i - 1
        dp[i][j] = cur;

        // cover s[i - 1]
        // dp[i][j] = max(dp[k][j - 1]) k <= i - len
        if (j > 0) {
          int cnt = (i - len >= 0 ? sum[i] - sum[i - len] : sum[i]);
          umax(dp[i][j], pre + cnt);
          if (i - len >= 0)
            umax(pre, dp[i - len + 1][j - 1]);
        }
        umax(cur, dp[i][j]);
        umax(ans, dp[i][j]);
      }
    }

    return sum[n] - ans;
  }
};
