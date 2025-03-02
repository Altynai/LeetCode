template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int longestPalindromicSubsequence(string s, int k) {
    int n = s.size();
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(n, vector<int>(k + 1, 0)));

    for (int i = n - 1; i >= 0; i--) {
      for (int op = 0; op <= k; op++)
        dp[i][i][op] = 1;
      for (int j = i + 1; j < n; j++) {
        for (int op = 0; op <= k; op++) {
          // skip s[i]
          umax(dp[i][j][op], dp[i + 1][j][op]);
          // skip s[j]
          umax(dp[i][j][op], dp[i][j - 1][op]);
          // match s[i] and s[j]
          int x = s[i] - 'a', y = s[j] - 'a';
          int z = abs(x - y);
          z = min(z, 26 - z);
          if (op + z <= k)
            umax(dp[i][j][op + z], dp[i + 1][j - 1][op] + 2);
        }
      }
    }
    return dp[0][n - 1][k];
  }
};
