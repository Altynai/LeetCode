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
// using mint = modnum<998244353>;

struct Prime {
  // primes <= sqrt(n)
  vector<int> init(int n) {
    bool p[n];
    for (int i = 0; i < n; i++)
      p[i] = 1;
    for (int i = 4; i < n; i += 2)
      p[i] = 0;
    for (int i = 3; i * i < n; i += 2) {
      if (!p[i])
        continue;
      for (int j = i * i; j < n; j += i)
        p[j] = 0;
    }
    vector<int> ret = {2};
    for (int i = 3; i < n; i += 2)
      if (p[i])
        ret.push_back(i);
    return ret;
  }
} prime;

#define maxn 10002
#define maxm 14

class Solution {
public:
  vector<int> waysToFillArray(vector<vector<int>> &queries) {
    vector<int> p = prime.init(maxn);
    vector<int> ans;

    // 2 ^ 14 > 10 ^ 4
    mint dp[maxn][maxm], s[maxn][maxm];

    // dp[i][j]: uniq ways of putting j balls into i buckets
    for (int j = 0; j < maxm; j++) {
      dp[1][j] = 1;
      s[1][j] = j + 1;
    }

    for (int i = 2; i < maxn; i++) {
      for (int j = 0; j < maxm; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j)
          dp[i][j] += s[i - 1][j - 1];

        if (j == 0)
          s[i][j] = dp[i][j];
        else
          s[i][j] = s[i][j - 1] + dp[i][j];
      }
    }

    for (auto &q : queries) {
      int val = q[1];
      int n = q[0];
      mint w = 1;
      for (int pp : p) {
        int cnt = 0;
        while (val > 1 && val % pp == 0) {
          cnt++;
          val /= pp;
        }
        if (cnt)
          w *= dp[n][cnt];
      }
      ans.push_back(int(w));
    }
    return ans;
  }
};
