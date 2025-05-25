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

// NOTE: only use when n ~ 10^5
struct Comb {
  vector<mint> fac;

  Comb() {}
  Comb(int n) { init(n); }

  void init(int n) {
    fac.resize(n + 1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++)
      fac[i] = fac[i - 1] * i;
  }

  mint choose(int n, int r) {
    if (n < r)
      return 0;
    if (r == 0)
      return 1;
    return fac[n] / fac[r] / fac[n - r];
  }

  // if n is quite big and r is small
  mint choose2(int n, int r) {
    if (n < r)
      return 0;
    if (n == r || r == 0)
      return 1;
    mint numerator = 1, denominator = 1;
    for (int i = 1; i <= r; i++)
      denominator *= i;
    for (int i = 0; i < r; i++)
      numerator *= (n - i);
    return numerator / denominator;
  }
} comb(1e5 + 1);

class Solution {
public:
  int assignEdgeWeights(vector<vector<int>> &edges) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      int u = e[0] - 1, v = e[1] - 1;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int dep = 0;
    function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
      dep = max(dep, d);
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        dfs(v, u, d + 1);
      }
    };
    dfs(0, -1, 0);

    mint ans = 0;
    for (int odd = 1; odd <= dep; odd += 2)
      ans += comb.choose(dep, odd);
    return int(ans);
  }
};
