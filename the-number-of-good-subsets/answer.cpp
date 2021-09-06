class Solution {
public:
  int numberOfGoodSubsets(vector<int> &a) {
    const vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    const int m = 10;
    const int MOD = 1e9 + 7;

    auto add = [&](int &x, int y) {
      x += y % MOD;
      x %= MOD;
    };

    auto getMask = [&](int x) {
      if (x % 4 == 0 || x % 9 == 0 || x % 16 == 0 || x % 25 == 0)
        return -1;
      int mask = 0;
      for (int j = 0; j < m; j++) {
        if (x % p[j] == 0)
          mask |= 1 << j;
      }
      return mask;
    };

    int n = a.size(), one = 0;
    vector<int> cnt(31, 0);
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
        one++;
        continue;
      }
      int mask = getMask(a[i]);
      if (mask != -1)
        cnt[a[i]]++;
    }

    vector<int> dp(1 << m, 0);
    dp[0] = 1;

    for (int i = 2; i <= 30; i++) {
      if (cnt[i] == 0)
        continue;
      int mask = getMask(i);

      vector<int> ndp = dp;
      for (int j = 0; j < (1 << m); j++) {
        if ((j & mask) == 0)
          add(ndp[j | mask], 1LL * cnt[i] * dp[j] % MOD);
      }
      dp = ndp;
    }

    int ans = 0;
    for (int i = 1; i < (1 << m); i++)
      add(ans, dp[i]);
    while (one--)
      ans = 2LL * ans % MOD;
    return ans;
  }
};
