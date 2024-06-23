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

const int M = 400;

class Solution {
public:
  int numberOfPermutations(int n, vector<vector<int>> &req) {
    vector<int> cnt(n, -1);
    for (auto v : req)
      cnt[v[0]] = v[1];
    if (cnt[0] > 0)
      return 0;

    // dp[i][j]: use 0 ~ i, j inversions
    // for 0 ~ i - 1, we can consider to insert i in different places
    // dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + ... + dp[i - 1][j - i]
    vector<mint> dp(M + 1, 0), prefix(M + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
      vector<mint> ndp(M + 1, 0);

      prefix[0] = dp[0];
      for (int j = 1; j <= M; j++)
        prefix[j] = prefix[j - 1] + dp[j];

      int inv = (1 + i) * i / 2;
      for (int j = 0; j <= min(M, inv); j++) {
        int k = max(0, j - i);
        ndp[j] += (k == 0 ? prefix[j] : prefix[j] - prefix[k - 1]);
      }

      if (cnt[i] != -1) {
        for (int j = 0; j <= min(M, inv); j++) {
          if (j != cnt[i])
            ndp[j] = 0;
        }
      }
      swap(dp, ndp);
    }
    return int(dp[cnt[n - 1]]);
  }
};
