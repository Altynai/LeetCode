struct SegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  static const int MAXN = 100004 << 2;

  int L[MAXN], R[MAXN];
  int nodes[MAXN];

  void build(int p, int l, int r) {
    L[p] = l, R[p] = r;
    if (l == r) {
      nodes[p] = 0;
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid);
      build(rson(p), mid + 1, r);
      pull(p);
    }
  }

  void pull(int p) { nodes[p] = max(nodes[lson(p)], nodes[rson(p)]); }

  void update(int p, int pos, const int &val) {
    if (L[p] == R[p]) {
      nodes[p] = max(nodes[p], val);
      return;
    }
    int mid = (L[p] + R[p]) >> 1;
    if (pos <= mid)
      update(lson(p), pos, val);
    else
      update(rson(p), pos, val);
    pull(p);
  }

  int query(int p, int l, int r) {
    if (L[p] == l && R[p] == r)
      return nodes[p];

    int mid = (L[p] + R[p]) >> 1;
    if (r <= mid)
      return query(lson(p), l, r);
    else if (l > mid)
      return query(rson(p), l, r);
    else {
      return max(query(lson(p), l, mid), query(rson(p), mid + 1, r));
    }
  }
} st;

class Solution {
public:
  int lengthOfLIS(vector<int> &a, int k) {
    int n = a.size();
    int M = *max_element(a.begin(), a.end());

    vector<int> dp(M + 1, 0);
    st.build(1, 1, M);

    for (int i = 0; i < n; i++) {
      int l = max(1, a[i] - k), r = max(1, a[i] - 1);
      int x = 0;
      if (l <= r and r < a[i])
        x = st.query(1, l, r);

      dp[a[i]] = max(dp[a[i]], x + 1);
      st.update(1, a[i], dp[a[i]]);
    }
    return *max_element(dp.begin(), dp.end());
  }
};
