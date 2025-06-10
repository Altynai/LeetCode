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

struct BinaryLifting {
  int n, m;
  vector<vector<int>> g;
  vector<int> depth;
  vector<vector<int>> jump;

  BinaryLifting(int _n, const vector<vector<int>> &_g) : n(_n), g(_g) {
    m = (int)log2(n) + 1;
    depth.resize(n);
    jump.resize(n);
    for (int i = 0; i < n; i++) {
      depth[i] = -1;
      jump[i] = vector<int>(m, -1);
    }
  }

  void dfs(int u, int fa, int d) {
    jump[u][0] = fa;
    depth[u] = d;
    for (int v : g[u]) {
      if (v == fa)
        continue;
      dfs(v, u, d + 1);
    }
  }

  // =================== Public APIs ===================
  void rootify(int root) {
    dfs(root, -1, 0);

    for (int p = 1; p < m; p++) {
      for (int i = 0; i < n; i++) {
        int k = jump[i][p - 1];
        if (k != -1)
          jump[i][p] = jump[k][p - 1];
      }
    }
  }

  int lca(int u, int v) {
    if (depth[u] < depth[v])
      swap(u, v);

    int dist = depth[u] - depth[v];
    for (int p = 0; p < m; p++) {
      if (dist & (1 << p)) {
        u = jump[u][p];
      }
    }
    if (u == v)
      return u;

    for (int p = m - 1; p >= 0; p--) {
      if (jump[u][p] != jump[v][p])
        u = jump[u][p], v = jump[v][p];
    }
    return jump[u][0];
  }

  int dist(int u, int v) {
    int node = lca(u, v);
    return depth[u] + depth[v] - depth[node] * 2;
  }
};

class Solution {
public:
  vector<int> assignEdgeWeights(vector<vector<int>> &edges,
                                vector<vector<int>> &queries) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      int u = e[0] - 1, v = e[1] - 1;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    BinaryLifting bin(n, adj);
    bin.rootify(0);

    int m = queries.size();
    vector<int> ans(m, 0);
    for (int i = 0; i < m; i++) {
      int u = queries[i][0] - 1, v = queries[i][1] - 1;
      int d = bin.dist(u, v);
      if (d > 0)
        ans[i] = (int)(mint(2).pow(d - 1));
    }
    return ans;
  }
};
