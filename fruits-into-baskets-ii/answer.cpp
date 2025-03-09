struct SegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  static const int MAXN = 100004 << 2;

  int L[MAXN], R[MAXN];
  int nodes[MAXN];

  void build(int p, int l, int r, const vector<int> &v) {
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

  void pull(int p) { nodes[p] = max(nodes[lson(p)], nodes[rson(p)]); }

  void update(int p, int pos, const int &val) {
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

  int query(int p, int val) {
    if (L[p] == R[p])
      return nodes[p] >= val ? L[p] : -1;
    if (nodes[lson(p)] >= val)
      return query(lson(p), val);
    if (nodes[rson(p)] >= val)
      return query(rson(p), val);
    return -1;
  }
};

SegmentTree st;

class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n = fruits.size();
    st.build(1, 0, n - 1, baskets);

    int ans = 0;
    for (int i = 0; i < n; i++) {
      int pos = st.query(1, fruits[i]);
      if (pos == -1)
        ans++;
      else
        st.update(1, pos, 0);
    }
    return ans;
  }
};
