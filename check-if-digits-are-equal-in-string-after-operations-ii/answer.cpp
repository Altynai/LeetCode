// Generated by Perplexity
class Combinatorics {
private:
  static const int MOD5 = 5;
  static const int MOD = 10;
  std::vector<std::vector<int>> lut;

  int mod5_comb(int n, int r) {
    int res = 1;
    while (n > 0 || r > 0) {
      int a = n % MOD5;
      int b = r % MOD5;
      if (b > a)
        return 0;
      res = (res * lut[a][b]) % MOD5;
      n /= MOD5;
      r /= MOD5;
    }
    return res;
  }

public:
  Combinatorics() {
    lut.resize(5, std::vector<int>(5, 0));
    lut[0][0] = 1;
    lut[1][0] = 1;
    lut[1][1] = 1;
    lut[2][0] = 1;
    lut[2][1] = 2;
    lut[2][2] = 1;
    lut[3][0] = 1;
    lut[3][1] = 3;
    lut[3][2] = 3;
    lut[3][3] = 1;
    lut[4][0] = 1;
    lut[4][1] = 4;
    lut[4][2] = 1;
    lut[4][3] = 4;
    lut[4][4] = 1;
  }

  int nCr(int n, int r) {
    if (r < 0 || r > n)
      return 0;
    int mod2 = ((n & r) == r) ? 1 : 0;
    int mod5 = mod5_comb(n, r);
    return (5 * mod2 + 6 * mod5) % MOD;
  }
} comb;

class Solution {
public:
  int calculate(const string &s) {
    int n = s.size(), res = 0;
    for (int i = 0; i < n; i++) {
      res += comb.nCr(n - 1, i) * (s[i] - '0');
      res %= 10;
    }
    return res;
  }

  bool hasSameDigits(string s) {
    int n = s.size();
    int x = calculate(s.substr(0, n - 1));
    int y = calculate(s.substr(1));
    return x == y;
  }
};
