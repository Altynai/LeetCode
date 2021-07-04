class Solution {
public:
  int countGoodNumbers(long long n) {
    const int MOD = 1e9 + 7;

    auto pow = [&](long long x, long long m) {
      long long ans = 1, p = x;
      while (m) {
        if (m & 1)
          ans = ans * p % MOD;
        p = p * p % MOD;
        m >>= 1;
      }
      return ans;
    };

    long long ans = 5;
    // even
    ans = ans * pow(5, (n - 1) / 2) % MOD;
    // odd
    ans = ans * pow(4, n - 1 - (n - 1) / 2) % MOD;
    return ans;
  }
};
