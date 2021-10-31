class Solution {
public:
  bool possiblyEquals(string s1, string s2) {
    int n = s1.size(), m = s2.size();

    // max delta len: 999 + 1
    const int BASE = 1000;
    const int LIMIT = BASE * 2;
    bool dp[n + 1][m + 1][LIMIT + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][BASE] = true;

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        for (int delta = 0; delta <= LIMIT; delta++) {
          if (!dp[i][j][delta])
            continue;

          if (i < n) {
            if (islower(s1[i])) {
              // char vs char
              if (j < m && islower(s2[j]) && s1[i] == s2[j] && delta == BASE)
                dp[i + 1][j + 1][delta] = true;
              // char vs number
              if (j && isdigit(s2[j - 1]) && delta + 1 <= BASE)
                dp[i + 1][j][delta + 1] = true;
            } else {
              // number vs ?
              for (int k = i; k < n && isdigit(s1[k]); k++) {
                int ndelta = delta + stoi(s1.substr(i, k - i + 1));
                if (ndelta <= LIMIT)
                  dp[k + 1][j][ndelta] = true;
              }
            }
          }

          if (j < m) {
            if (islower(s2[j])) {
              // char vs char
              if (i < n && islower(s1[i]) && s1[i] == s2[j] && delta == BASE)
                dp[i + 1][j + 1][delta] = true;
              // number vs char
              if (i && isdigit(s1[i - 1]) && delta - 1 >= BASE)
                dp[i][j + 1][delta - 1] = true;
            } else {
              // ? vs number
              for (int k = j; k < m && isdigit(s2[k]); k++) {
                int ndelta = delta - stoi(s2.substr(j, k - j + 1));
                if (ndelta >= 0)
                  dp[i][k + 1][ndelta] = true;
              }
            }
          }
        }
      }
    }
    return dp[n][m][BASE];
  }
};
