template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

template <class Info> struct SegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  static const int MAXN = 100004 << 2;

  int L[MAXN], R[MAXN];
  Info nodes[MAXN];

  void build(int p, int l, int r) {
    L[p] = l, R[p] = r;
    if (l == r) {
      nodes[p] = Info();
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid);
      build(rson(p), mid + 1, r);
      pull(p);
    }
  }

  void build(int p, int l, int r, const string &s) {
    L[p] = l, R[p] = r;
    if (l == r) {
      nodes[p] = Info(s[l] - '0');
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid, s);
      build(rson(p), mid + 1, r, s);
      pull(p);
    }
  }

  void pull(int p) { nodes[p] = nodes[lson(p)] + nodes[rson(p)]; }

  void update(int p, int pos, const Info &val) {
    if (L[p] == R[p]) {
      nodes[p] = val;
      return;
    }
    int mid = (L[p] + R[p]) >> 1;
    if (pos <= mid)
      update(lson(p), pos, val);
    else
      update(rson(p), pos, val);
    pull(p);
  }

  Info query(int p, int l, int r) {
    if (L[p] == l && R[p] == r)
      return nodes[p];

    int mid = (L[p] + R[p]) >> 1;
    if (r <= mid)
      return query(lson(p), l, r);
    else if (l > mid)
      return query(rson(p), l, r);
    else {
      return query(lson(p), l, mid) + query(rson(p), mid + 1, r);
    }
  }
};

struct Merger {

  vector<pair<int, int>> v;
  int m = 0;

  void init() { m = 0, v.resize(6); }

  void push_back(const pair<int, int> &p) {
    if (m > 0 and p.first == v[m - 1].first)
      v[m - 1].second += p.second;
    else
      v[m++] = p;
  }
} merger;

struct Node {
  array<int, 3> l_lens; // 0, 1, 0 or 1, 0, 1
  int l_val;            // left first value

  array<int, 3> r_lens;
  int r_val;

  int len;  // total length
  int best; // best of 0, 1, 0

  Node() {}
  Node(int _v) {
    l_val = _v;
    l_lens = {1, 0, 0};

    r_val = _v;
    r_lens = {0, 0, 1};

    len = 1;
    best = 0;
  }

  bool is_full_range() const {
    return l_lens[0] + l_lens[1] + l_lens[2] == len;
  }

  friend Node operator+(const Node &a, const Node &b) {
    Node c;

    c.l_val = a.l_val;
    c.l_lens = a.l_lens;

    c.r_val = b.r_val;
    c.r_lens = b.r_lens;

    c.len = a.len + b.len;
    c.best = max(a.best, b.best);

    // update left
    merger.init();
    if (a.is_full_range()) {
      for (int i = 0, val = a.l_val; i < 3 and a.l_lens[i] > 0; i++, val ^= 1) {
        merger.push_back({val, a.l_lens[i]});
      }
      for (int i = 0, val = b.l_val; i < 3 and b.l_lens[i] > 0; i++, val ^= 1) {
        merger.push_back({val, b.l_lens[i]});
      }

      int m = min(3, merger.m);
      c.l_val = merger.v[0].first;
      c.l_lens = {0, 0, 0};
      for (int i = 0; i < m; i++)
        c.l_lens[i] = merger.v[i].second;
      if (c.l_val == 0 and m == 3)
        umax(c.best, c.l_lens[0] + c.l_lens[2]);
    }

    // update right
    merger.init();
    if (b.is_full_range()) {
      for (int i = 2, val = b.r_val; i >= 0; i--, val ^= 1) {
        if (b.r_lens[i] == 0)
          continue;
        merger.push_back({val, b.r_lens[i]});
      }
      for (int i = 2, val = a.r_val; i >= 0; i--, val ^= 1) {
        if (a.r_lens[i] == 0)
          continue;
        merger.push_back({val, a.r_lens[i]});
      }

      int m = min(3, merger.m);
      c.r_val = merger.v[0].first;
      c.r_lens = {0, 0, 0};
      for (int i = 0, j = 2; i < m; i++, j--)
        c.r_lens[j] = merger.v[i].second;
      if (c.r_val == 0 and m == 3)
        umax(c.best, c.r_lens[0] + c.r_lens[2]);
    }

    // update middle
    if (a.r_val == b.l_val) {

      // 0, 1, 0, | 0, 1, 0
      //    <- a  | b ->
      if (a.r_val == 0) {
        if (a.r_lens[0] > 0) {
          umax(c.best, a.r_lens[0] + a.r_lens[2] + b.l_lens[0]);
        }
        if (b.l_lens[2] > 0)
          umax(c.best, a.r_lens[2] + b.l_lens[0] + b.l_lens[2]);
      }
      // 1, 0, 1, | 1, 0, 1
      //    <- a  | b ->
      else {
        if (a.r_lens[1] > 0 and b.l_lens[1] > 0)
          umax(c.best, a.r_lens[1] + b.l_lens[1]);
      }
    } else {

      // 0, 1, 0, | 1, 0, 1
      //    <- a  | b ->
      if (a.r_val == 0) {
        if (b.r_lens[1] > 0)
          umax(c.best, a.r_lens[2] + b.l_lens[1]);
      }
      // 1, 0, 1, | 0, 1, 0
      //    <- a  | b ->
      else {
        if (a.r_lens[1] > 0)
          umax(c.best, a.r_lens[1] + b.l_lens[0]);
      }
    }

    return c;
  }
};

SegmentTree<Node> st;

class Solution {
public:
  vector<int> maxActiveSectionsAfterTrade(string s,
                                          vector<vector<int>> &queries) {
    int n = s.size();
    st.build(1, 0, n - 1, s);

    int cnt = count(s.begin(), s.end(), '1');

    int m = queries.size();
    vector<int> ans(m, cnt);
    for (int i = 0; i < m; i++) {
      int l = queries[i][0], r = queries[i][1];
      auto res = st.query(1, l, r);
      ans[i] += res.best;
    }
    return ans;
  }
};
