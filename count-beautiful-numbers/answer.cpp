const int N = 81;

int dp[2][N][N + 1][2];

class Solution {
public:
  int beautifulNumbers(int l, int r) {
    int ans = 0, sum = to_string(r).size() * 9;
    for (int i = 1; i <= sum; i++)
      ans += count(r, i) - count(l - 1, i);
    return ans;
  }

  int count(int n, int sum) {
    if (n == 0)
      return 0;

    string s = to_string(n);
    int m = s.size();
    if (sum > m * 9)
      return 0;

    // dp[i][product % sum][current_sum][less_or_equal]
    // (10 * 81 * 81 * 2) * 81 ~ 1e7
    int pre = 0, now = 1;
    init(dp[pre], sum);
    dp[pre][0][0][1] = 1;

    for (int i = 0; i < m; i++) {
      int val = s[i] - '0';
      init(dp[now], sum);

      for (int mod = 0; mod < sum; mod++) {
        for (int curr = 0; curr <= sum; curr++) {
          for (int digit = 0; digit <= 9 and curr + digit <= sum; digit++) {
            int mod2 = mod * digit % sum;
            if (curr == 0 and digit == 0)
              mod2 = 0;
            else if (curr == 0 and digit > 0)
              mod2 = digit % sum;

            // still same
            if (digit == val) {
              dp[now][mod2][curr + digit][1] += dp[pre][mod][curr][1];
            }

            // should be less
            if (digit < val) {
              dp[now][mod2][curr + digit][0] += dp[pre][mod][curr][1];
              dp[now][mod2][curr + digit][0] += dp[pre][mod][curr][0];
            } else {
              dp[now][mod2][curr + digit][0] += dp[pre][mod][curr][0];
            }
          }
        }
      }
      swap(pre, now);
    }
    return dp[pre][0][sum][0] + dp[pre][0][sum][1];
  }

  void init(int f[N][N + 1][2], int sum) {
    for (int mod = 0; mod < sum; mod++) {
      for (int curr = 0; curr <= sum; curr++)
        f[mod][curr][0] = f[mod][curr][1] = 0;
    }
  }
};
