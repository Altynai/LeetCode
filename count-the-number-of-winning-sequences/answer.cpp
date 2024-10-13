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
  int creature(char ch) {
    int res = 0; // 'W'
    if (ch == 'F')
      res = 1;
    else if (ch == 'E')
      res = 2;
    return res;
  }

  int award(int bob, int alice) {
    if (bob == alice)
      return 0;
    return (bob + 1) % 3 == alice ? 1 : -1;
  }

public:
  int countWinningSequences(string s) {
    // W > F > E > W
    int n = s.size();

    // WFE
    // 012

    // dp[i][j][k]: Bob chooses j-th creature with k delta awarded points after
    // i-th round

    vector<unordered_map<int, mint>> dp(3);

    int alice = creature(s[0]);
    for (int cur = 0; cur < 3; cur++)
      dp[cur][award(cur, alice)] += 1;

    for (int i = 2; i <= n; i++) {
      int alice = creature(s[i - 1]);

      vector<unordered_map<int, mint>> ndp(3);
      for (int last = 0; last < 3; last++) {
        for (int cur = 0; cur < 3; cur++) {
          if (last == cur)
            continue;
          for (auto [points, cnt] : dp[last])
            ndp[cur][points + award(cur, alice)] += cnt;
        }
      }
      swap(dp, ndp);
    }

    mint ans = 0;
    for (int cur = 0; cur < 3; cur++) {
      for (auto [points, cnt] : dp[cur]) {
        if (points > 0)
          ans += cnt;
      }
    }
    return int(ans);
  }
};
