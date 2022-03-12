const int MOD = 1e9 + 7;

void add(int &x, int y) {
  x += y;
  x %= MOD;
}

class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    auto valid = [&](int pos, int val) -> bool {
      if (val == 0)
        return s[pos - 1] == '0';
      return s[pos - 1] == '*' or s[pos - 1] == char('0' + val);
    };

    for (int i = 1; i <= 9; i++)
      if (valid(1, i))
        dp[1]++;

    for (int i = 2; i <= n; i++) {
      for (int j = 1; j <= 9; j++) {
        if (valid(i, j))
          add(dp[i], dp[i - 1]);
      }
      for (int j = 10; j <= 26; j++) {
        if (valid(i, j % 10) and valid(i - 1, j / 10))
          add(dp[i], dp[i - 2]);
      }
    }

    return dp[n];
  }
};
