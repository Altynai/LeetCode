#define bit(n, i) (((n) >> (i)) & 1)

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

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

using State = pair<int, int>; // mask, score

const int N = 10;

class Solution {
public:
  int getMask(int val) {
    int mask = 0;
    while (val > 0) {
      int x = val % 10;
      if (bit(mask, x))
        return -1;
      mask |= (1 << x);
      val /= 10;
    }
    return mask;
  }

  int goodSubtreeSum(vector<int> &vals, vector<int> &par) {
    // dp[u][mask]: max score in subtree rooted at u with mask

    int n = vals.size();
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
      adj[par[i]].push_back(i);

    mint ans = 0;
    function<vector<State>(int)> dfs = [&](int u) -> vector<State> {
      int mask = getMask(vals[u]);
      if (adj[u].size() == 0) {
        if (mask == -1)
          return {};
        ans += vals[u];
        return {{mask, vals[u]}};
      }

      vector<int> res(1 << N, -1);
      res[0] = 0;
      for (int v : adj[u]) {
        auto states = dfs(v);
        for (auto [_mask, _score] : states) {
          for (int m = 1; m < (1 << N); m++) {
            if ((m & _mask) == _mask and res[m - _mask] != -1)
              umax(res[m], res[m - _mask] + _score);
          }
        }
      }
      if (mask != -1) {
        umax(res[mask], vals[u]);
        for (int m = 1; m < (1 << N); m++) {
          if ((m & mask) == mask and res[m - mask] != -1) {
            umax(res[m], res[m - mask] + vals[u]);
          }
        }
      }

      vector<State> states;
      int best = 0;
      for (int m = 1; m < (1 << N); m++) {
        if (res[m] == -1)
          continue;
        umax(best, res[m]);
        states.push_back({m, res[m]});
      }
      ans += best;
      return states;
    };

    dfs(0);
    return int(ans);
  }
};
1
