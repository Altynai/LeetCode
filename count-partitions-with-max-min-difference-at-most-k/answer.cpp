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

template <class T> class MinOp {
public:
  T operator()(T a, T b) { return min(a, b); }
};

template <class T> class MaxOp {
public:
  T operator()(T a, T b) { return max(a, b); }
};

// example usage:
// RMQ<int, MinOp<int>> rmq;
// rmq.init(v);
template <typename T, typename OpFunc> struct RMQ {

  const static int N = 50002;
  const static int M = 16; // 2^M >= N

  T val[N][M];
  OpFunc opFunc = OpFunc();

  void init(const vector<T> &_val) {
    int n = _val.size();
    for (int i = 0; i < n; i++) {
      val[i][0] = _val[i];
    }

    for (int j = 1; j <= log((double)n) / log(2.0); j++) {
      for (int i = 0; i + (1 << j) - 1 < n; i++) {
        val[i][j] = opFunc(val[i][j - 1], val[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  T query(int a, int b) {
    assert(a <= b);
    int k = (int)(log((double)b - a + 1) / log(2.0));
    return opFunc(val[a][k], val[b - (1 << k) + 1][k]);
  }
};

class Solution {
public:
  int countPartitions(vector<int> &a, int k) {
    int n = a.size();
    a.insert(a.begin(), -1);

    vector<mint> sum(n + 1, 0);
    sum[0] = 1;

    auto Get = [&](int l, int r) -> mint {
      if (l <= 0)
        return sum[r];
      return sum[r] - sum[l - 1];
    };

    RMQ<int, MinOp<int>> min_rmq;
    RMQ<int, MaxOp<int>> max_rmq;
    min_rmq.init(a);
    max_rmq.init(a);

    vector<int> positions(n + 1, 1);
    mint ans = 0;

    for (int i = 1; i <= n; i++) {
      int pos1 = i;
      for (int l = 1, r = i - 1; l <= r;) {
        int mid = (l + r) / 2;
        if (min_rmq.query(mid, i - 1) >= a[i] - k)
          pos1 = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      int pos2 = i;
      for (int l = 1, r = i - 1; l <= r;) {
        int mid = (l + r) / 2;
        if (max_rmq.query(mid, i - 1) <= a[i] + k)
          pos2 = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      positions[i] = max(pos1, pos2);
      positions[i] = max(positions[i], positions[i - 1]);

      // [pos, pos + 1, ..., i] are all valid
      sum[i] = sum[i - 1] + Get(positions[i] - 1, i - 1);
    }
    return int(sum[n] - sum[n - 1]);
  }
};
1
