const int MOD = 1e9 + 7;

class Solution {
public:
  void add(int &x, int y) {
    x += y % MOD;
    x %= MOD;
  }

  bool isPrime(char c) { return c == '2' or c == '3' or c == '5' or c == '7'; }

  int beautifulPartitions(string s, int k, int minLength) {
    int n = s.size();
    if (!isPrime(s[0]) or isPrime(s[n - 1]))
      return 0;

    vector<int> goodEnd(n + 1, 0);
    goodEnd[0] = goodEnd[n] = 1;
    for (int i = 1; i < n; i++) {
      if (!isPrime(s[i - 1]) and isPrime(s[i]))
        goodEnd[i] = 1;
    }

    vector<int> dp(n + 1, 0), sum(n + 1, 1);
    dp[0] = 1;

    for (int i = 1; i <= k; i++) {
      vector<int> ndp(n + 1, 0), nsum(n + 1, 0);

      for (int j = 1; j <= n; j++) {
        if (!goodEnd[j])
          continue;
        int pos = j - minLength + 1;
        if (pos >= 1)
          add(ndp[j], sum[pos - 1]);
      }

      for (int j = 1; j <= n; j++) {
        nsum[j] = nsum[j - 1];
        if (goodEnd[j])
          add(nsum[j], ndp[j]);
      }
      dp = ndp, sum = nsum;
    }

    return dp[n];
  }
};
