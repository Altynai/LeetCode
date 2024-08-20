using int64 = long long;

struct LazySegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  const static int MAXN = 100004 << 2;

  // basic fields
  int L[MAXN], R[MAXN];

  // maintained fields
  int tag[MAXN];
  int64 sum[MAXN];

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
    sum[p] += int64(newVal) * rangeSize(p);
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

  int64 query(int p, int l, int r) {
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
  vector<long long> countKConstraintSubstrings(string s, int k,
                                               vector<vector<int>> &queries) {
    // length of good string maybe > 2k, e.g. 01111111111..1111
    // how to count good string's boundary?
    // for a starting point i:
    // * s[i ... j0] has k 0's
    // * s[i ... j1] has k 1's
    // let p = max(j0, j1)
    // hence everything between i and p is good
    // this gives a hint to perform a range add on a segment tree

    int n = s.size();
    int m = queries.size();
    vector<array<int, 3>> v(m);
    for (int i = 0; i < m; i++)
      v[i] = {queries[i][1], queries[i][0], i};
    sort(v.begin(), v.end());

    st.build(1, 0, n - 1);

    vector<int64> ans(m);
    vector<int> cnt(2, 0);
    for (int r = 0, l = 0, i = 0; r < n; r++) {
      cnt[s[r] - '0']++;
      while (cnt[0] > k and cnt[1] > k)
        cnt[s[l++] - '0']--;
      st.rangeUpdate(1, l, r, +1);
      while (i < m and v[i][0] == r) {
        ans[v[i][2]] = st.query(1, v[i][1], r);
        i++;
      }
    }
    return ans;
  }
};
