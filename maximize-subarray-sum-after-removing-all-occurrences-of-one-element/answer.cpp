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

  void build(int p, int l, int r, const vector<Info> &v) {
    L[p] = l, R[p] = r;
    if (l == r) {
      nodes[p] = v[l];
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid, v);
      build(rson(p), mid + 1, r, v);
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

using int64 = long long;

struct Node {

  int64 l_max, r_max, sum, res;

  Node() { l_max = r_max = sum = res = LLONG_MIN; }
  Node(int64 v) { l_max = r_max = sum = res = v; }

  bool empty() const { return sum == LLONG_MIN; }

  friend Node operator+(const Node &a, const Node &b) {
    if (a.empty())
      return b;
    else if (b.empty())
      return a;

    int64 l_max = max(a.l_max, a.sum + b.l_max);
    int64 r_max = max(b.r_max, b.sum + a.r_max);
    int64 res = max(a.res, b.res);
    umax(res, a.r_max + b.l_max);

    Node c;
    c.l_max = l_max;
    c.r_max = r_max;
    c.sum = a.sum + b.sum;
    c.res = res;
    return c;
  }
};

SegmentTree<Node> st;

class Solution {
public:
  long long maxSubarraySum(vector<int> &a) {
    // maximum subarray sum = pref[i] - min(pref[j]) j < i
    // it's not optimal to delete a non-negative element

    // we can maintain a node in segment tree
    // node information: left/right maximum sum, maximum sum
    // delete/re-add element once, so it will still be NlogN
    // if elemenet is deleted, then no left/right maximum sum

    int n = a.size();
    vector<Node> v(n);

    unordered_map<int, vector<int>> where;
    for (int i = 0; i < n; i++) {
      v[i] = Node(a[i]);
      where[a[i]].push_back(i);
    }

    st.build(1, 0, n - 1, v);
    auto q = st.query(1, 0, n - 1);
    int64 ans = q.res;
    for (auto [x, positions] : where) {
      for (int pos : positions)
        st.update(1, pos, Node());
      q = st.query(1, 0, n - 1);
      umax(ans, q.res);
      for (int pos : positions)
        st.update(1, pos, Node(x));
    }
    return ans;
  }
};
