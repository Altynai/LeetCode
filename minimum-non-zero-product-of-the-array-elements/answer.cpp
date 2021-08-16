class Solution {
public:
  int minNonZeroProduct(int p) {
    long long n = (1LL << p) - 1;
    long long m = n / 2;
    const long long MOD = 1e9 + 7;
    long long res = n % MOD, q = (n - 1) % MOD;
    while (m) {
      if (m & 1)
        res = res * q % MOD;
      q = q * q % MOD;
      m /= 2;
    }
    return res % MOD;
  }
};
