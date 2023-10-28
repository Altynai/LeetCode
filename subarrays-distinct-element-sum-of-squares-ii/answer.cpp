template <int MOD_>
struct modnum {
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
    modnum() : v(0) {};
    modnum(int64 v_) : v(int(v_ % MOD)) {
        if (v < 0) v += MOD;
    }
    explicit operator int() const { return v; }
    friend std::ostream& operator<<(std::ostream& out, const modnum& n) { return out << int(n); }
    friend std::istream& operator>>(std::istream& in, modnum& n) {
        int64 v_;
        in >> v_;
        n = modnum(v_);
        return in;
    }
    friend bool operator==(const modnum& a, const modnum& b) { return a.v == b.v; }
    friend bool operator!=(const modnum& a, const modnum& b) { return a.v != b.v; }

    modnum inv() const {
        modnum res;
        res.v = minv(v, MOD);
        return res;
    }
    friend modnum inv(const modnum& m) { return m.inv(); }
    modnum neg() const {
        modnum res;
        res.v = v ? MOD - v : 0;
        return res;
    }
    friend modnum neg(const modnum& m) { return m.neg(); }

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

    modnum& operator++() {
        ++v;
        if (v == MOD) v = 0;
        return *this;
    }
    modnum& operator--() {
        if (v == 0) v = MOD;
        --v;
        return *this;
    }
    modnum& operator+=(const modnum& o) {
        v += o.v;
        if (v >= MOD) v -= MOD;
        return *this;
    }
    modnum& operator-=(const modnum& o) {
        v -= o.v;
        if (v < 0) v += MOD;
        return *this;
    }
    modnum& operator*=(const modnum& o) {
        v = int(int64(v) * int64(o.v) % MOD);
        return *this;
    }
    modnum& operator/=(const modnum& o) { return *this *= o.inv(); }

    friend modnum operator++(modnum& a, int) {
        modnum r = a;
        ++a;
        return r;
    }
    friend modnum operator--(modnum& a, int) {
        modnum r = a;
        --a;
        return r;
    }
    friend modnum operator+(const modnum& a, const modnum& b) { return modnum(a) += b; }
    friend modnum operator-(const modnum& a, const modnum& b) { return modnum(a) -= b; }
    friend modnum operator*(const modnum& a, const modnum& b) { return modnum(a) *= b; }
    friend modnum operator/(const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using mint = modnum<1000000007>;
// using mint = modnum<998244353>;

using int64 = long long;

struct LazySegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  const static int MAXN = 100004 << 2;

  // basic fields
  int L[MAXN], R[MAXN];

  // maintained fields
  int tag[MAXN];
  mint sum[MAXN];

  inline int rangeSize(int p) { return R[p] - L[p] + 1; }

  void build(int p, int l, int r) {
    L[p] = l, R[p] = r, tag[p] = 0;
    if (l == r) {
      sum[p] = 0;
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid);
      build(rson(p), mid + 1, r);
      pull(p);
    }
  }
  
  void tagNode(int p, int newVal) {
    tag[p] += newVal;
    sum[p] += mint(newVal) * rangeSize(p);
  }

  void push(int p) {
    // can't push down on leaf nodes
    assert(L[p] != R[p]);
    if (tag[p]) {
      tagNode(lson(p), tag[p]);
      tagNode(rson(p), tag[p]);
    }
    tag[p] = 0;
  }

  void pull(int p) {
    // can't pull on leaf nodes
    assert(L[p] != R[p]);
    sum[p] = sum[lson(p)] + sum[rson(p)];
  }

  void rangeUpdate(int p, int l, int r, int newValue) {
    // case 1: update leaf node
    if (L[p] == R[p]) {
      sum[p] += newValue;
    }
    // case 2: covers the entire range
    else if (L[p] == l && R[p] == r) {
      tagNode(p, newValue);
    }
    // case 3: may need to split the range
    else {
      // make sure to call push before doing rangeSet on child nodes
      push(p);
      int mid = (L[p] + R[p]) >> 1;
      if (r <= mid)
        rangeUpdate(lson(p), l, r, newValue);
      else if (l > mid)
        rangeUpdate(rson(p), l, r, newValue);
      else {
        rangeUpdate(lson(p), l, mid, newValue);
        rangeUpdate(rson(p), mid + 1, r, newValue);
      }
      // make sure to call pill after doing rangeSet on child nodes
      pull(p);
    }
  }

  mint query(int p, int l, int r) {
    // case 1: query leaf node
    if (L[p] == R[p]) {
      return sum[p];
    }
    // case 2: covers the entire range
    else if (L[p] == l && R[p] == r) {
      return sum[p];
    }
    // case 3: may need to split the range
    else {
      // make sure to call push before doing query on child nodes
      push(p);
      int mid = (L[p] + R[p]) >> 1;
      if (r <= mid)
        return query(lson(p), l, r);
      else if (l > mid)
        return query(rson(p), l, r);
      else {
        return query(lson(p), l, mid) + query(rson(p), mid + 1, r);
      }
    }
  }
} st;

class Solution {
public:
    int sumCounts(vector<int>& a) {
      int n = a.size();
      
      vector<mint> dp(n + 1, 0);
      unordered_map<int, int> last;
      st.build(1, 1, n);

      mint ans = 0;
      for (int i = 1; i <= n;i++) {
        int num = a[i - 1];
        auto it = last.find(num);
        int idx = (it != last.end() ?it->second:0);

        // case: [1, idx]
        // nothing changes, it's already calcualted in dp[i - 1]
        dp[i] = dp[i - 1];
        
        /* 
        * case: [idx, i - 1]
        *  for each range [j, i - 1] ( idx <= j <= i - 1)
        *  if A dentates the uniq count for range [j, i - 1]
        *  then we have (A + 1)^2 = A^2 + 2*A + 1
        *    * since dp[i - 1] has already included the A^2 part
        *    * so we just need to add 2*A + 1 to dp[i]
        *  
        *  query: S = sum(uniq count of [j, r], l <= j <= r)
        *  update: every position between [idx, r] will increase by 1
        */
        dp[i] += st.query(1, idx + 1, i) * 2 + (i - idx);
        st.rangeUpdate(1, idx + 1, i, 1);

        ans += dp[i];
        last[num] = i;
      }
      return int(ans);
    }
};
