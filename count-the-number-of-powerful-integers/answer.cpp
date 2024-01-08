const int N = 10;
using int64 = long long;

class Solution {
private:
  int64 cal(int64 num, int limit, string suffix) {
    if (stoll(suffix, nullptr, 10) > num)
      return 0;

    string s = to_string(num);
    int n = s.size(), m = suffix.size();

    // first digit
    int digit = s[0] - '0';
    vector<vector<int64>> dp(N, vector<int64>(2, 0));
    int l = 0, r = min(limit, digit);
    if (n == m)
      l = r = suffix[0] - '0';
    for (int d = l; d <= r; d++) {
      if (d < digit)
        dp[d][0] = 1;
      if (d == digit)
        dp[d][1] = 1;
    }

    for (int i = 1; i < n; i++) {
      vector<vector<int64>> ndp(N, vector<int64>(2, 0));

      digit = s[i] - '0';
      l = 0, r = limit;
      if (i >= n - m)
        l = r = suffix[m - (n - i)] - '0';

      for (int d = l; d <= r; d++) {
        for (int j = 0; j < N; j++) {
          ndp[d][0] += dp[j][0];
          if (d < digit)
            ndp[d][0] += dp[j][1];
          if (d == digit)
            ndp[d][1] += dp[j][1];
        }
      }
      swap(dp, ndp);
    }

    digit = suffix[m - 1] - '0';
    return dp[digit][0] + dp[digit][1];
  }

public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                string s) {
    return cal(finish, limit, s) - cal(start - 1, limit, s);
  }
};
