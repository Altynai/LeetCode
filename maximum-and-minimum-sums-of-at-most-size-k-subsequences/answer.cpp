template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

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

template <class T> struct Comb {
  static const int N = 1e5 + 1;
  static const int M = 71;

  T C[N][M];

  void init(int n, int m) {
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= m; j++)
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  T choose(int n, int r) {
    if (n < r)
      return 0;
    if (r == 0)
      return 1;
    return C[n][r];
  }
};

class Solution {
private:
  Comb<mint> cb;

public:
  int minMaxSums(vector<int> &a, int k) {
    int n = a.size();

    cb.init(n, k);

    unordered_map<int, int> freq;
    for (int x : a)
      freq[x]++;

    vector<int> b = a;
    int m = deduplicate(b);

    mint ans = 0;
    for (int i = 0, pcnt = 0; i < m; i++) {
      int cnt = freq[b[i]];
      int scnt = n - pcnt - cnt;
      for (int seq = 1; seq <= k; seq++) {
        mint ways = cb.choose(pcnt + cnt, seq) - cb.choose(pcnt, seq);
        ans += ways * b[i];
        ways = cb.choose(scnt + cnt, seq) - cb.choose(scnt, seq);
        ans += ways * b[i];
      }
      pcnt += cnt;
    }
    return int(ans);
  }
};
