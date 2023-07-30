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
private:
  bool check(const string &s) {
    int n = s.size();
    for (int i = 1; i < n; i++) {
      int d = abs(s[i] - s[i - 1]);
      if (d != 1)
        return 0;
    }
    return 1;
  }

public:
  int countSteppingNumbers(string low, string high) {
    int n = low.size(), m = high.size();
    vector<vector<mint>> cnt(m + 1, vector<mint>(10, 0));
    for (int i = 0; i <= 9; i++)
      cnt[1][i] = 1;
    for (int j = 2; j <= m; j++) {
      for (int i = 0; i <= 9; i++) {
        if (i)
          cnt[j][i] += cnt[j - 1][i - 1];
        if (i < 9)
          cnt[j][i] += cnt[j - 1][i + 1];
      }
    }

    auto Count = [&](const string &s) -> mint {
      int len = s.size();
      int d = s[0] - '0';
      if (len == 1)
        return d + 1;

      mint ans = 0;
      // case 1: less len
      for (int j = 1; j < len; j++) {
        for (int i = (j == 1 ? 0 : 1); i <= 9; i++)
          ans += cnt[j][i];
      }

      // case 2: same len
      // i: last digit
      // j: 1 equal, 0 less
      vector<vector<mint>> dp(10, vector<mint>(2, 0));
      for (int i = 1; i < d; i++)
        dp[i][0] = 1;
      dp[d][1] = 1;

      for (int j = 2; j <= len; j++) {
        vector<vector<mint>> ndp(10, vector<mint>(2, 0));
        d = s[j - 1] - '0';
        // less
        for (int i = 0; i <= 9; i++) {
          if (i) {
            ndp[i][0] += dp[i - 1][0];
            if (i < d)
              ndp[i][0] += dp[i - 1][1];
          }
          if (i < 9) {
            ndp[i][0] += dp[i + 1][0];
            if (i < d)
              ndp[i][0] += dp[i + 1][1];
          }
        }
        // same
        if (d)
          ndp[d][1] += dp[d - 1][1];
        if (d < 9)
          ndp[d][1] += dp[d + 1][1];

        dp = ndp;
      }

      for (int i = 0; i <= 9; i++)
        ans += dp[i][0] + dp[i][1];
      return ans;
    };

    mint ans = Count(high) - Count(low);
    if (check(low))
      ans++;
    return int(ans);
  }
};
