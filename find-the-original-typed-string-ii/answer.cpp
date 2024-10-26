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
public:
  int possibleStringCount(string s, int k) {
    // first to compress the string for sure
    // e.g. 7a 2b 9c, etc...
    int n = s.size();
    vector<int> comp;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and s[j] == s[i])
        j++;
      comp.push_back(j - i);
      i = j;
    }

    int m = comp.size();

    mint total = 1;
    for (int cnt : comp)
      total *= cnt;

    // if # of unique chars is already >= k, then simple multiplication
    if (m >= k)
      return int(total);

    // # of unique chars is < k and assuming its m
    // then we need firstly select k - m extra chars
    // as # group of chars is < k, maybe O(k^2) dp?

    // ans = total # of strings - # of at most k - 1 length
    // dp[i][j]: until i-th group, we have select j chars
    // dp[i + 1][x] = dp[i][x - 1] + dp[i][x] + .... + dp[i][x - cnt]
    // the right side can be sped up with prefix sum

    vector<mint> dp(k, 0), psum(k, 1);
    dp[0] = 1;
    for (int i = 0; i < m; i++) {
      vector<mint> ndp(k, 0);
      for (int x = 1; x < k; x++) {
        int r = x - 1, l = max(0, x - comp[i]);
        ndp[x] = psum[r] - (l == 0 ? 0 : psum[l - 1]);
      }

      swap(dp, ndp);
      for (int j = 0; j < k; j++)
        psum[j] = (j > 0 ? psum[j - 1] : 0) + dp[j];
    }
    return int(total - psum[k - 1]);
  }
};
