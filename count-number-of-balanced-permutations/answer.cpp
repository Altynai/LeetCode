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

const int N = 81;

class Solution {
private:
  vector<vector<mint>> C;

public:
  Solution() {
    // NOTE: good performance with pre-calculation
    C = vector<vector<mint>>(N + 1, vector<mint>(N + 1, 0));
    C[0][0] = 1;
    for (int i = 1; i <= N; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++)
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  int countBalancedPermutations(string s) {
    // dp[digit][cnt][sum]: used [0 ... digit], selected cnt even positions,
    // with that sum

    // transition: for digit + 1, we can choose some k within [0 ... cnt]
    // and add to even positions (needs combinatorics), the rest goes to
    // odd positions (same with combinatorics)

    // time: 10 * 40 * 360 * 80 ~ 1e7

    int n = s.size(), sum = 0;
    vector<int> freq(10, 0);
    for (int i = 0; i < n; i++) {
      freq[s[i] - '0']++;
      sum += s[i] - '0';
    }
    if (sum % 2 == 1)
      return 0;

    sum /= 2;
    int even = (n + 1) / 2;
    int odd = n - even;

    vector<vector<mint>> dp(even + 1, vector<mint>(sum + 1, 0));
    dp[0][0] = 1;

    for (int digit = 0; digit <= 9; digit++) {
      if (freq[digit] == 0)
        continue;

      vector<vector<mint>> ndp(even + 1, vector<mint>(sum + 1, 0));
      for (int j = 0; j <= even; j++) {
        for (int k = 0; k <= sum; k++) {

          // valid spots for placing new digit on odd positions
          int places =
              odd - (accumulate(freq.begin(), freq.begin() + digit, 0) - j);
          if (places < 0)
            continue;

          for (int pick = 0; pick <= freq[digit]; pick++) {
            if (j + pick > even)
              continue;
            if (k + digit * pick > sum)
              continue;

            // even
            mint ways = C[even - j][pick];
            // odd
            ways *= C[places][freq[digit] - pick];

            ndp[j + pick][k + digit * pick] += dp[j][k] * ways;
          }
        }
      }

      swap(dp, ndp);
    }
    return int(dp[even][sum]);
  }
};
