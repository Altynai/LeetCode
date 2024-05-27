using int64 = long long;

template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

template <class Info> struct SegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  static const int MAXN = 50007 << 2;

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

struct Node {
  // maximum sum if we do or do not choose 2 endpoints
  int64 vals[2][2];

  Node() {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        vals[i][j] = LLONG_MIN;
      }
    }
  }

  Node(int64 v) {
    vals[0][0] = 0;
    vals[1][1] = v;
    vals[0][1] = vals[1][0] = LLONG_MIN;
  }

  int64 max() {
    int64 res = LLONG_MIN;
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        umax(res, vals[i][j]);
      }
    }
    assert(res != LLONG_MIN);
    return res;
  }

  friend Node operator+(const Node &a, const Node &b) {
    Node c;
    // only choose from one segment
    for (int l0 = 0; l0 < 2; l0++) {
      for (int r0 = 0; r0 < 2; r0++) {
        if (a.vals[l0][r0] != LLONG_MIN)
          umax(c.vals[l0][r0], a.vals[l0][r0]);
        if (b.vals[l0][r0] != LLONG_MIN)
          umax(c.vals[l0][r0], b.vals[l0][r0]);
      }
    }

    // merge segments
    for (int l0 = 0; l0 < 2; l0++) {
      for (int r0 = 0; r0 < 2; r0++) {
        if (a.vals[l0][r0] == LLONG_MIN)
          continue;

        for (int l1 = 0; l1 < 2; l1++) {
          for (int r1 = 0; r1 < 2; r1++) {
            if (b.vals[l1][r1] == LLONG_MIN)
              continue;
            if (r0 == 1 and l1 == 1)
              continue;
            umax(c.vals[l0][r1], a.vals[l0][r0] + b.vals[l1][r1]);
          }
        }
      }
    }
    return c;
  }
};

SegmentTree<Node> st;

class Solution {
public:
  int maximumSumSubsequence(vector<int> &a, vector<vector<int>> &queries) {
    int n = a.size();
    vector<Node> vals(n);
    for (int i = 0; i < n; i++)
      vals[i] = Node(a[i]);

    st.build(1, 0, n - 1, vals);

    int ans = 0, m = queries.size();
    const int MOD = 1e9 + 7;
    for (int i = 0; i < m; i++) {
      int pos = queries[i][0], x = queries[i][1];
      st.update(1, pos, Node(x));
      Node res = st.query(1, 0, n - 1);
      cout << res.max() << endl;
      ans += res.max() % MOD;
      ans %= MOD;
    }
    return ans;
  }
};
