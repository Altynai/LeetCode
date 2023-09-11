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
using int64 = long long;

const int HASH_P = 998244353;

struct Matrix {
  mint mat[2][2] = {0};

  Matrix(){};
  Matrix(int n) {
    mat[0][0] = 0, mat[0][1] = 1;
    mat[1][0] = n - 1, mat[1][1] = n - 2;
  }

  friend Matrix operator*(const Matrix &a, const Matrix &b) {
    Matrix res;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        res.mat[i][j] = 0;
        for (int k = 0; k < 2; k++)
          res.mat[i][j] += a.mat[i][k] * b.mat[k][j];
      }
    }
    return res;
  }
};

class Solution {
public:
  int numberOfWays(string s, string t, long long k) {
    int n = s.size();

    mint hashS = 0, hashT = 0, power = 1;
    for (int i = 0; i < n; i++) {
      hashS += power * s[i];
      hashT += power * t[i];
      power *= HASH_P;
    }
    power /= HASH_P;

    vector<int> v; // number of good shifts positions
    for (int i = 0; i < n; i++) {
      if (hashS == hashT)
        v.push_back(i);

      hashS -= power * s[n - 1 - i];
      hashS *= HASH_P;
      hashS += s[n - 1 - i];
    }

    /*
    Q: how many ways to use k integers [1, n - 1] and add up to sum % n = shift

    f[k, 0] -> shift = 0
    f[k, 1] -> shift != 0

    f[k, 0] = (n - 1) * f[k - 1, 1]
    f[k, 1] = f[k - 1, 0] + (n - 2) * f[k - 1, 1]

    f[0, 0] = 1 = x
    f[0, 1] = 0 = y

    matrix multiplication
    [x, y] * [0     , 1    ]
             [n - 1 , n - 2]
    */
    Matrix res(n), p(n);
    for (int64 m = k - 1; m > 0; m /= 2) {
      if (m & 1)
        res = res * p;
      p = p * p;
    }

    mint ans = 0, zero = res.mat[0][0], nonZero = res.mat[0][1];
    for (int shift : v) {
      if (shift == 0)
        ans += zero;
      else
        ans += nonZero;
    }
    return int(ans);
  }
};
