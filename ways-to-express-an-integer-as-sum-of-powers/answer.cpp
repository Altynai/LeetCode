const int MOD = 1e9 + 7;

void add(int &x, int y) {
  y %= MOD;
  x = (x + y) % MOD;
}

class Solution {
public:
  int numberOfWays(int n, int x) {
    if (x == 1) {
      vector<int> dp(n + 1, 0);
      dp[0] = 1;
      for (int i = 1; i <= n; i++) {
        vector<int> ndp = dp;
        for (int sum = 0; sum + i <= n; sum++)
          add(ndp[sum + i], dp[sum]);
        dp = ndp;
      }
      return dp[n];
    }

    int m = 1;
    vector<int> p = {0};
    while (true) {
      int val = pow(m, x);
      if (val <= n)
        p.push_back(val);
      else
        break;
      m++;
    }
    m -= 1;

    // we have 2^m state in total
    int ans = 0;
    for (int mask = 1; mask < (1 << m); mask++) {
      int sum = 0;
      for (int i = 0; sum <= n and i < m; i++) {
        if (mask & (1 << i))
          sum += p[i + 1];
      }
      if (sum == n)
        ans++;
    }
    return ans;
  }
};
