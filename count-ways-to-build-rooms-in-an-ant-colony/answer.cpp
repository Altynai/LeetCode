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

  modnum pow(int m) {
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

struct Comb {
  vector<mint> fac;

  void init(int n) {
    fac.resize(n + 1);
    fac[0] = fac[1] = 1;
    for (int i = 2; i <= n; i++)
      fac[i] = fac[i - 1] * i;
  }

  mint nCr(int n, int r) {
    if (n < r)
      return 0;
    if (r == 0)
      return 1;
    return fac[n] / fac[r] / fac[n - r];
  }

  // if n is quite big and r is smalls
  mint nCr2(int n, int r) {
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
} comb;

class Solution {
public:
  int waysToBuildRooms(vector<int> &father) {
    int n = father.size();
    comb.init(n + 1);

    vector<vector<int>> g(n, vector<int>());
    vector<int> size(n, 0);
    for (int i = 1; i < n; i++)
      g[father[i]].push_back(i);

    function<mint(int)> dfs = [&](int u) -> mint {
      size[u] = 1;
      if (g[u].size() == 0) {
        return 1;
      }

      int m = g[u].size();
      vector<mint> ways(m);
      for (int i = 0; i < m; i++) {
        ways[i] = dfs(g[u][i]);
        size[u] += size[g[u][i]];
      }

      int remain = size[u] - 1;
      mint ans = 1;
      for (int i = 0; i < m; i++) {
        ans *= ways[i] * comb.nCr(remain, size[g[u][i]]);
        remain -= size[g[u][i]];
      }
      return ans;
    };
    return int(dfs(0));
  }
};
