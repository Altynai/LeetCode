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
  int v;

  Node() { v = 0; }
  Node(int v) { this->v = v; }

  friend Node operator+(const Node &a, const Node &b) {
    return Node(max(a.v, b.v));
  }
};
SegmentTree<Node> st;

class Solution {
public:
  vector<bool> getResults(vector<vector<int>> &queries) {
    int n = 0;
    for (auto q : queries)
      n = max(n, q[1]);

    st.build(1, 0, n);
    st.update(1, 0, Node(INT_MAX));

    set<int> obstacles = {0};

    int m = queries.size();
    vector<bool> ans;
    for (int i = 0; i < m; i++) {
      if (queries[i][0] == 1) {
        int x = queries[i][1];
        auto it = obstacles.lower_bound(x);
        // handle previous obstacle
        int pre = *prev(it);
        st.update(1, pre, Node(x - pre));
        // handle position x
        int len = (it == obstacles.end() ? INT_MAX : *it - x);
        st.update(1, x, Node(len));

        obstacles.insert(x);
      } else {
        int x = queries[i][1];
        int sz = queries[i][2];

        if (sz > x)
          ans.push_back(false);
        else {
          Node res = st.query(1, 0, x - sz);
          ans.push_back(res.v >= sz);
        }
      }
    }
    return ans;
  }
};
