// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}
// =====================================================================================================================

class Solution {
public:
  int maximumScore(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, INT_MIN));

    dp[1][0] = a[0] * b[0];
    dp[0][1] = a[n - 1] * b[0];

    for (int i = 0; i < m; i++) {
      for (int j = 0; i + j + 1 <= m; j++) {
        if (dp[i][j] == INT_MIN)
          continue;
        umax(dp[i + 1][j], dp[i][j] + a[i] * b[i + j]);
        umax(dp[i][j + 1], dp[i][j] + a[n - j - 1] * b[i + j]);
      }
    }

    int ans = INT_MIN;
    for (int i = 0; i <= m; i++)
      umax(ans, dp[i][m - i]);
    return ans;
  }
};
