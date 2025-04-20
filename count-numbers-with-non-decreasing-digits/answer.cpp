template <int MOD_> struct modnum {
  typedef long long int64;

  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");

private:
  int v;
  static int minv(int a, int m) {
    a %= m;
    assert(a);
    return a == 1 ? 1 : int(m - int64(minv(m, a)) * int64(m) / a);
  }

public:
  modnum() : v(0){};
  modnum(int64 v_) : v(int(v_ % MOD)) {
    if (v < 0)
      v += MOD;
  }
  explicit operator int() const { return v; }
  friend std::ostream &operator<<(std::ostream &out, const modnum &n) {
    return out << int(n);
  }
  friend std::istream &operator>>(std::istream &in, modnum &n) {
    int64 v_;
    in >> v_;
    n = modnum(v_);
    return in;
  }
  friend bool operator==(const modnum &a, const modnum &b) {
    return a.v == b.v;
  }
  friend bool operator!=(const modnum &a, const modnum &b) {
    return a.v != b.v;
  }

  modnum inv() const {
    modnum res;
    res.v = minv(v, MOD);
    return res;
  }
  friend modnum inv(const modnum &m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD - v : 0;
    return res;
  }
  friend modnum neg(const modnum &m) { return m.neg(); }

  modnum pow(int64 m) {
    assert(m >= 0);
    modnum res = 1, p = modnum(*this);
    while (m) {
      if (m & 1)
        res *= p;
      p *= p;
      m /= 2;
    }
    return res;
  }

  modnum operator-() const { return neg(); }
  modnum operator+() const { return modnum(*this); }

  modnum &operator++() {
    ++v;
    if (v == MOD)
      v = 0;
    return *this;
  }
  modnum &operator--() {
    if (v == 0)
      v = MOD;
    --v;
    return *this;
  }
  modnum &operator+=(const modnum &o) {
    v += o.v;
    if (v >= MOD)
      v -= MOD;
    return *this;
  }
  modnum &operator-=(const modnum &o) {
    v -= o.v;
    if (v < 0)
      v += MOD;
    return *this;
  }
  modnum &operator*=(const modnum &o) {
    v = int(int64(v) * int64(o.v) % MOD);
    return *this;
  }
  modnum &operator/=(const modnum &o) { return *this *= o.inv(); }

  friend modnum operator++(modnum &a, int) {
    modnum r = a;
    ++a;
    return r;
  }
  friend modnum operator--(modnum &a, int) {
    modnum r = a;
    --a;
    return r;
  }
  friend modnum operator+(const modnum &a, const modnum &b) {
    return modnum(a) += b;
  }
  friend modnum operator-(const modnum &a, const modnum &b) {
    return modnum(a) -= b;
  }
  friend modnum operator*(const modnum &a, const modnum &b) {
    return modnum(a) *= b;
  }
  friend modnum operator/(const modnum &a, const modnum &b) {
    return modnum(a) /= b;
  }
};
using mint = modnum<1000000007>;
// using mint = modnum<998244353>;

class Solution {

  /**
   * Converts a positive decimal string to its representation in the specified
   * base (2-10) Handles numbers up to 100 digits
   * @param s     A string containing a positive decimal number
   * @param base  The target base (2-10)
   * @return      String representation of the number in the target base
   */
  std::string convertToBase(const std::string &s, int base) {
    // Handle zero as a special case
    if (s == "0") {
      return "0";
    }

    // Convert to target base using repeated division
    std::string result;
    std::string current = s;

    while (!current.empty() && current != "0") {
      int remainder = 0;
      std::string next;

      // Perform division digit by digit
      for (char digit : current) {
        int currentDigit = (digit - '0') + remainder * 10;
        remainder = currentDigit % base;
        int quotient = currentDigit / base;

        // Skip leading zeros in the quotient
        if (!(next.empty() && quotient == 0)) {
          next.push_back('0' + quotient);
        }
      }

      // Add the remainder digit to the result
      result.push_back('0' + remainder);

      // Update current for the next iteration
      current = next.empty() ? "0" : next;
    }

    // Reverse the result
    std::reverse(result.begin(), result.end());

    return result;
  }

  mint countNumbers(const string &s, int base) {
    string t = convertToBase(s, base);
    int n = t.size();

    // dp[i][last_digit][less_or_equal]
    vector<vector<mint>> dp(base, vector<mint>(2, 0));
    dp[0][1] = 1;
    for (int i = 0; i < n; i++) {
      vector<vector<mint>> ndp(base, vector<mint>(2, 0));
      int digit = t[i] - '0';
      for (int last = 0; last < base; last++) {
        for (int eq = 0; eq <= 1; eq++) {
          //  each digit is greater than or equal to the previous one
          for (int choose = last; choose < base; choose++) {
            if (eq == 1 and choose > digit)
              continue;
            int eq2 = (eq == 1 and choose == digit);
            ndp[choose][eq2] += dp[last][eq];
          }
        }
      }
      swap(dp, ndp);
    }

    mint res = 0;
    for (int last = 0; last < base; last++) {
      res += dp[last][0];
      res += dp[last][1];
    }
    return res;
  }

public:
  int countNumbers(string l, string r, int b) {
    mint res = countNumbers(r, b) - countNumbers(l, b);

    string s = convertToBase(l, b);
    int n = s.size(), good = 1;
    for (int i = 1; i < n; i++) {
      if (s[i] < s[i - 1])
        good = 0;
    }
    if (good)
      res++;

    return int(res);
  }
};
