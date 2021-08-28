class Solution {
public:
  int numberOfCombinations(string s) {
    const int MOD = 1e9 + 7;

    auto add = [&](int &x, int y) {
      x += y % MOD;
      x %= MOD;
    };

    int n = s.size();
    if (s[0] == '0')
      return 0;

    vector<vector<int>> len(n, vector<int>(n, 0));
    for (int j = n - 1; j >= 0; j--) {
      for (int i = j - 1; i >= 0; i--) {
        int best = (i + 1 < n && j + 1 < n ? len[i + 1][j + 1] : 0);
        if (s[i] == s[j])
          len[i][j] = best + 1;
        else
          len[i][j] = 0;
      }
    }

    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    vector<vector<int>> sum = dp;

    dp[0][1] = 1;
    for (int j = 1; j <= n; j++)
      add(sum[0][j], sum[0][j - 1] + dp[0][j]);

    for (int i = 1; i < n; i++) {
      add(dp[i][i + 1], 1);
      for (int j = i; j >= 1; j--) {
        if (s[i - j + 1] == '0')
          continue;
        // equal len, compare s[i-j*2+1 ... i-j] with s[i-j+1 ... i]
        if (i - j * 2 + 1 >= 0 && s[i - j * 2 + 1] > '0') {
          int p = len[i - j * 2 + 1][i - j + 1];
          if (p >= j || s[i - j + 1 + p] > s[i - j * 2 + 1 + p])
            add(dp[i][j], dp[i - j][j]);
        }
        // less len
        add(dp[i][j], sum[i - j][j - 1]);
      }
      for (int j = 1; j <= n; j++)
        add(sum[i][j], sum[i][j - 1] + dp[i][j]);
    }
    return sum[n - 1][n];
  }
};
