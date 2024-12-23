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

const int N = 1001;
const int M = 6;

class Solution {

  vector<vector<mint>> C;

public:
  Solution() {
    C = vector<vector<mint>>(N, vector<mint>(M, 0));
    C[0][0] = 1;
    for (int i = 1; i < N; i++) {
      C[i][0] = 1;
      for (int j = 1; j < M; j++)
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  }

  int subsequencesWithMiddleMode(vector<int> &a) {
    int n = a.size();
    mint ans = 0;

    unordered_map<int, int> freq;
    for (int x : a)
      freq[x]++;

    // times = 1: impossible

    // times = 2: one same number, three different numbers
    unordered_map<int, int> before, after;
    before[a[0]]++, before[a[1]]++;
    for (int i = 3; i < n; i++)
      after[a[i]]++;

    // Great Improvement: sum of piles of choosing 2 from each pile
    mint before_choose_2 = 0, after_choose_2 = 0;
    for (auto [x, y] : before)
      before_choose_2 += C[y][2];
    for (auto [x, y] : after)
      after_choose_2 += C[y][2];

    for (int i = 2; i <= n - 3; i++) {
      // B A A C D
      for (auto [b, count] : before) {
        if (b == a[i])
          continue;
        mint left_ways = C[before[a[i]]][1] * count;
        // we can not choose a[i] or b from "after"
        // and also not choose same elements
        int num = n - 1 - i - after[a[i]] - after[b];
        mint right_ways =
            C[num][2] - (after_choose_2 - C[after[a[i]]][2] - C[after[b]][2]);
        ans += left_ways * right_ways;
      }

      // C D A A B
      for (auto [b, count] : after) {
        if (b == a[i])
          continue;
        mint left_ways = C[after[a[i]]][1] * count;
        // we can not choose a[i] or b from "before"
        // and also not choose same elements
        int num = i - before[a[i]] - before[b];
        mint right_ways = C[num][2] - (before_choose_2 - C[before[a[i]]][2] -
                                       C[before[b]][2]);
        ans += left_ways * right_ways;
      }

      before_choose_2 -= C[before[a[i]]][2];
      before[a[i]]++;
      before_choose_2 += C[before[a[i]]][2];

      if (i + 1 < n) {
        after_choose_2 -= C[after[a[i + 1]]][2];
        after[a[i + 1]]--;
        after_choose_2 += C[after[a[i + 1]]][2];
      }
    }

    // times = 3: two same number, rest doesn'matter but can't be equal to
    // seq[2]
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
      if (i >= 2 and i <= n - 3) {
        int l = cnt[a[i]], r = freq[a[i]] - cnt[a[i]] - 1;
        // B C A A A
        ans += C[i - l][2] * C[r][2];
        // A A A B C
        ans += C[l][2] * C[n - 1 - i - r][2];
        // B A A A C
        ans += C[i - l][1] * C[l][1] * C[r][1] * C[n - 1 - i - r][1];
      }
      cnt[a[i]]++;
    }

    // times = 4: three same number, rest doesn'matter but can't be equal to
    // seq[2]
    cnt.clear();
    for (int i = 0; i < n; i++) {
      if (i >= 2 and i <= n - 3) {
        int l = cnt[a[i]], r = freq[a[i]] - cnt[a[i]] - 1;
        // B A A A A
        ans += C[l][1] * (i - l) * C[r][2];
        // A A A A B
        ans += C[l][2] * (n - 1 - i - r) * C[r][1];
      }
      cnt[a[i]]++;
    }

    // times = 5: easy case
    for (auto [k, v] : freq) {
      if (v >= 5)
        ans += C[v][5];
    }
    return int(ans);
  }
};
