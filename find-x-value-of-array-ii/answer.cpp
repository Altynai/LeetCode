template <class Info> struct SegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  static const int MAXN = 100004 << 2;

  int L[MAXN], R[MAXN];
  Info nodes[MAXN];

  void build(int p, int l, int r, const vector<int> &v, const int mod) {
    L[p] = l, R[p] = r;
    if (l == r) {
      nodes[p] = Info(mod, v[l]);
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid, v, mod);
      build(rson(p), mid + 1, r, v, mod);
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
  int mod;
  int prod; // prod of the whole segment
  vector<int> cnt;

  Node() {}

  Node(int mod) {
    this->mod = mod;

    cnt.resize(mod);
    cnt.assign(mod, 0);
  }

  Node(int mod, int v) : Node(mod) {
    cnt[v % mod]++;
    prod = v % mod;
  }

  friend Node operator+(const Node &a, const Node &b) {
    assert(a.mod == b.mod);
    int mod = a.mod;

    Node c(mod);
    c.prod = a.prod * b.prod % mod;
    c.cnt = a.cnt;

    for (int i = 0; i < mod; i++) {
      c.cnt[a.prod * i % mod] += b.cnt[i];
    }
    return c;
  }
};

SegmentTree<Node> st;

class Solution {
public:
  vector<int> resultArray(vector<int> &a, int k, vector<vector<int>> &queries) {
    int n = a.size();
    st.build(1, 0, n - 1, a, k);

    int m = queries.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
      int pos = queries[i][0];
      int val = queries[i][1];
      st.update(1, pos, Node(k, val));

      int start = queries[i][2];
      int x = queries[i][3];
      auto res = st.query(1, start, n - 1);
      ans[i] = res.cnt[x];
    }
    return ans;
  }
};
