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
  int longestPalindrome(string a, string b) {
    string c = a + b;
    int n = c.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    int ans = 0;
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
      for (int j = i - 1; j >= 0; j--) {
        if (c[j] == c[i]) {
          umax(dp[j][i], dp[j + 1][i - 1] + 2);
        } else {
          umax(dp[j][i], dp[j + 1][i]);
          umax(dp[j][i], dp[j][i - 1]);
        }
      }
    }

    for (int j = 0; j < a.size(); j++) {
      for (int i = a.size(); i < n; i++) {
        if (c[j] == c[i])
          umax(ans, dp[j][i]);
      }
    }
    return ans;
  }
};
