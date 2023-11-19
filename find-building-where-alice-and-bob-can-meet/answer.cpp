struct SegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  static const int MAXN = 50004 << 2;

  int L[MAXN], R[MAXN];
  int nodes[MAXN];

  void build(int p, int l, int r) {
    L[p] = l, R[p] = r;
    if (l == r) {
      nodes[p] = INT_MAX;
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid);
      build(rson(p), mid + 1, r);
      pull(p);
    }
  }

  void pull(int p) { nodes[p] = min(nodes[lson(p)], nodes[rson(p)]); }

  void update(int p, int pos, const int &val) {
    if (L[p] == R[p]) {
      nodes[p] = min(nodes[p], val);
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
      return min(query(lson(p), l, mid), query(rson(p), mid + 1, r));
    }
  }
} st;

template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

class Solution {
public:
  vector<int> leftmostBuildingQueries(vector<int> &heights,
                                      vector<vector<int>> &queries) {
    int n = heights.size();

    vector<int> h = heights;
    int m = deduplicate(h);

    auto GetIndex = [&](int val) -> int {
      return lower_bound(h.begin(), h.end(), val) - h.begin();
    };

    int q = queries.size();
    vector<array<int, 3>> sq(q); // sorted queries
    for (int i = 0; i < q; i++) {
      int l = min(queries[i][0], queries[i][1]);
      int r = max(queries[i][0], queries[i][1]);
      sq[i] = {l, r, i};
    }
    sort(sq.begin(), sq.end(),
         [](const auto &lh, const auto &rh) { return lh[1] < rh[1]; });

    st.build(1, 0, m - 1);
    vector<int> ans(q, -1);
    for (int i = q - 1, j = n - 1; i >= 0; i--) {
      int l = sq[i][0], r = sq[i][1], qidx = sq[i][2];
      if (l == r or heights[l] < heights[r]) {
        ans[qidx] = r;
        continue;
      }

      while (j > r) {
        int pos = GetIndex(heights[j]);
        st.update(1, pos, j);
        j--;
      }

      int idx = GetIndex(max(heights[l], heights[r]));
      if (idx + 1 < m) {
        int res = st.query(1, idx + 1, m - 1);
        ans[qidx] = (res == INT_MAX ? -1 : res);
      }
    }
    return ans;
  }
};
