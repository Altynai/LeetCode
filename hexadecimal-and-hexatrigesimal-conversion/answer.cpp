class Solution {
public:
  string hex(int n, int mod) {
    string s;
    while (n > 0) {
      int m = n % mod;
      if (m <= 9)
        s.push_back('0' + m);
      else
        s.push_back('A' + (m - 10));
      n /= mod;
    }
    reverse(s.begin(), s.end());
    return s;
  }

  string concatHex36(int n) { return hex(n * n, 16) + hex(n * n * n, 36); }
};
