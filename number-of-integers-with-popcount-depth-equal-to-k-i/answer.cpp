#define bitCount(n) __builtin_popcountll((n))

using int64 = long long;

class Solution {
public:
  std::string toBinary(int64 n) {
    if (n == 0)
      return "0";

    std::string s = "";
    while (n > 0) {
      s += (n % 2) ? '1' : '0';
      n /= 2;
    }

    // Reverse since we built it backwards
    std::reverse(s.begin(), s.end());
    return s;
  }

  long long popcountDepth(long long n, int k) {
    if (k == 0)
      return 1;

    vector<int> cnt(65, 0);
    cnt[1] = 0;
    for (int i = 2; i <= 64; i++)
      cnt[i] = cnt[bitCount(i)] + 1;

    string s = toBinary(n);
    int m = s.size();

    // dp[pos][ones][equal]
    vector<vector<vector<int64>>> dp(
        m, vector<vector<int64>>(65, vector<int64>(2, 0)));
    dp[0][0][0] = 1;
    dp[0][1][1] = 1;
    for (int i = 1; i < m; i++) {
      int d = s[i] - '0';
      for (int j = 0; j <= i; j++) {
        // choose 0
        dp[i][j][0] += dp[i - 1][j][0];
        if (d == 1)
          dp[i][j][0] += dp[i - 1][j][1];
        else
          dp[i][j][1] += dp[i - 1][j][1];

        // choose 1
        dp[i][j + 1][0] += dp[i - 1][j][0];
        if (d == 1)
          dp[i][j + 1][1] += dp[i - 1][j][1];
      }
    }

    int64 ans = 0;
    for (int i = 1; i <= m; i++) {
      if (cnt[i] != k - 1)
        continue;
      ans += dp[m - 1][i][0] + dp[m - 1][i][1];
    }
    if (k == 1)
      return ans - 1;
    return ans;
  }
};
