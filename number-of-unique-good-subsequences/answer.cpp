const int MOD = 1e9 + 7;

void add(int &x, int y) {
  x += y % MOD;
  if (x < 0)
    x += MOD;
  x %= MOD;
}

class Solution {
public:
  int numberOfUniqueGoodSubsequences(string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0), sum(n + 1, 0);
    sum[n] = dp[n] = 1;

    vector<int> last(2, -1);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      int p = last[s[i] - '0'];
      if (p == -1)
        add(dp[i], sum[i + 1]);
      else
        add(dp[i], sum[i + 1] - sum[p + 1]);

      last[s[i] - '0'] = i;
      add(sum[i], sum[i + 1] + dp[i]);

      if (s[i] == '1')
        add(ans, dp[i]);
    }

    if (s.find('0') != -1)
      add(ans, 1);
    return ans;
  }
};
