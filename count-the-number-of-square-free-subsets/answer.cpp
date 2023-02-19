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

const vector<int> P = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
const int N = P.size();

class Solution {
public:
  int squareFreeSubsets(vector<int> &a) {
    sort(a.begin(), a.end());

    int n = a.size();
    vector<mint> dp(1 << N, 0);
    dp[0] = 1;

    mint ans = 0;
    int one = 0;
    for (int j = 0; j < n; j++) {
      if (a[j] == 1) {
        one++;
        continue;
      }

      vector<mint> ndp = dp;

      int m = 0, x = a[j];
      bool ok = true;
      for (int i = 0; ok and i < N; i++) {
        int cnt = 0;
        while (x % P[i] == 0)
          cnt++, x /= P[i];

        if (cnt >= 2)
          ok = false;
        else if (cnt & 1)
          m |= (1 << i);
      }

      if (ok and m > 0) {
        for (int mask = 0; mask < (1 << N); mask++) {
          if (mask & m)
            continue;
          ndp[mask ^ m] += dp[mask];
        }
      }

      dp = ndp;
    }

    for (int mask = 1; mask < (1 << N); mask++)
      ans += dp[mask];
    if (one > 0) {
      ans += dp[0];
      ans *= mint(2).pow(one);
      ans -= 1; // we can not both choose empty 1's and empty valid subset
    }

    return int(ans);
  }
};
