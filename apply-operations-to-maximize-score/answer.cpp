using int64 = long long;

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

struct PrimeFactorization {

  // primes.size() <= sqrt(n)
  vector<int> primes;
  vector<bool> p;

  PrimeFactorization(int n) {
    p.resize(n);
    p.assign(n, true);

    p[0] = p[1] = 0;
    for (int i = 4; i < n; i += 2)
      p[i] = 0;
    for (int i = 3; i * i < n; i += 2) {
      if (!p[i])
        continue;
      for (int j = i * i; j < n; j += i)
        p[j] = 0;
    }

    primes = {2};
    for (int i = 3; i < n; i += 2)
      if (p[i])
        primes.push_back(i);
  }

  vector<pair<int, int>> getFactors(int n) {
    vector<pair<int, int>> ans;
    for (int i = 0; n > 1 && i < (int)primes.size(); i++) {
      int cnt = 0;
      while (n % primes[i] == 0) {
        n /= primes[i];
        cnt++;
      }
      if (cnt)
        ans.emplace_back(primes[i], cnt);
    }
    if (n > 1)
      ans.emplace_back(n, 1);
    return ans;
  }
} prime_factorization(320); // sqrt(1e5)

struct RMQ {

  int n;
  int m; // 2^M >= N
  vector<vector<int>> ma;

  inline bool valid(int x) { return 0 <= x && x < n; }

  void init(const vector<int> &val) {
    n = val.size(), m = 0;
    while ((1 << m) < n)
      m++;
    m++;

    ma.resize(n);
    for (int i = 0; i < n; i++)
      ma[i].resize(m);

    for (int i = 0; i < n; i++)
      ma[i][0] = val[i];

    for (int j = 1; j <= log((double)n) / log(2.0); j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        ma[i][j] = max(ma[i][j - 1], ma[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int getMax(int a, int b) {
    assert(a <= b && valid(a) && valid(b));
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return max(ma[a][k], ma[b - (1 << k) + 1][k]);
  }
} rmq;

class Solution {
public:
  int maximumScore(vector<int> &a, int k) {
    int n = a.size();

    // prime score
    vector<int> ps(n);
    for (int i = 0; i < n; i++)
      ps[i] = prime_factorization.getFactors(a[i]).size();

    rmq.init(ps);

    map<int, vector<int>> where;
    for (int i = 0; i < n; i++)
      where[a[i]].push_back(i);

    mint ans = 1;
    for (auto it = where.rbegin(); it != where.rend(); it++) {
      int x = it->first;
      const vector<int> &idx = it->second;

      for (int pos : idx) {
        int L = pos;
        for (int l = 0, r = pos - 1; l <= r;) {
          int mid = (l + r) / 2;
          if (rmq.getMax(mid, pos - 1) < ps[pos])
            L = mid, r = mid - 1;
          else
            l = mid + 1;
        }
        int R = pos;
        for (int l = pos + 1, r = n - 1; l <= r;) {
          int mid = (l + r) / 2;
          if (rmq.getMax(pos + 1, mid) <= ps[pos])
            R = mid, l = mid + 1;
          else
            r = mid - 1;
        }

        int64 choice = 1LL * (pos - L + 1) * (R - pos + 1);
        int d = k;
        if (choice < 1LL * k)
          d = choice;

        ans *= mint(x).pow(d);

        k -= d;
        if (k == 0)
          break;
      }
    }
    return int(ans);
  }
};
