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
      nodes[p] = nodes[p] + val;
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
  Node(int _v) { v = _v; }

  friend Node operator+(const Node &a, const Node &b) {
    Node c(max(a.v, b.v));
    return c;
  }
};
SegmentTree<Node> st;

template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

class Solution {
public:
  int maxPathLength(vector<vector<int>> &coordinates, int k) {
    int n = coordinates.size();

    vector<int> ys;
    for (int i = 0; i < n; i++)
      ys.push_back(coordinates[i][1]);
    int m = deduplicate(ys);

    vector<array<int, 3>> cs(n);
    for (int i = 0; i < n; i++) {
      int id =
          lower_bound(ys.begin(), ys.end(), coordinates[i][1]) - ys.begin();
      cs[i] = {coordinates[i][0], id, i};
    }
    sort(cs.begin(), cs.end());

    vector<int> prefix(n, 1);
    st.build(1, 0, m - 1);
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n and cs[j][0] == cs[i][0]) {
        auto [_, id, pos] = cs[j];
        if (id > 0)
          prefix[pos] = st.query(1, 0, id - 1).v + 1;
        j++;
      }
      while (i < j) {
        auto [_, id, pos] = cs[i];
        st.update(1, id, Node(prefix[pos]));
        i++;
      }
    }

    vector<int> suffix(n, 1);
    st.build(1, 0, m - 1);
    for (int i = n - 1; i >= 0;) {
      int j = i;
      while (j >= 0 and cs[j][0] == cs[i][0]) {
        auto [_, id, pos] = cs[j];
        if (id + 1 < m)
          suffix[pos] = st.query(1, id + 1, m - 1).v + 1;
        j--;
      }
      while (i > j) {
        auto [_, id, pos] = cs[i];
        st.update(1, id, Node(suffix[pos]));
        i--;
      }
    }

    return prefix[k] + suffix[k] - 1;
  }
};
