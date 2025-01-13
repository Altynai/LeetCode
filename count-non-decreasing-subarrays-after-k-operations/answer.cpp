using int64 = long long;

struct LazySegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  const static int MAXN = 100004 << 2;

  // basic fields
  int L[MAXN], R[MAXN];

  // maintained fields
  int64 tag[MAXN];
  int64 sum[MAXN];
  int64 pfx[MAXN]; // prefix sum

  inline int rangeSize(int p) { return R[p] - L[p] + 1; }

  void init(const vector<int> &a) {
    pfx[0] = a[0];
    for (int i = 1; i < a.size(); i++)
      pfx[i] = pfx[i - 1] + a[i];
  }

  int64 rangeSum(int l, int r) {
    if (l == 0)
      return pfx[r];
    return pfx[r] - pfx[l - 1];
  }

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
    tag[p] = newVal;
    sum[p] = 1LL * newVal * rangeSize(p) - rangeSum(L[p], R[p]);
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
      sum[p] = 1LL * newValue - rangeSum(L[p], R[p]);
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

  int query(int p, int64 k) {
    if (L[p] == R[p]) {
      return k >= sum[p] ? R[p] : -1;
    }
    push(p);
    int mid = (L[p] + R[p]) >> 1;
    if (k < sum[lson(p)])
      return query(lson(p), k);

    int got = query(rson(p), k - sum[lson(p)]);
    if (got != -1)
      return got;
    return R[lson(p)];
  }
} st;

class Solution {
public:
  long long countNonDecreasingSubarrays(vector<int> &a, int k) {
    // for each a[i], we need to find the nearest a[j] that:
    // max(a[i + 1 .... j - 1]) <= a[i] < a[j]

    // we need to use k operations on a[i + 1 ... j - 1] and try to set
    // all of them to a[i], can be done with a range set in segement tree

    // now it's more of less to query along the segment tree to see which
    // farthest postition starting from i has as a range sum <= k

    int n = a.size();

    st.init(a);
    st.build(1, 0, n - 1);

    stack<int> stk;
    stk.push(n - 1);

    int64 ans = 1;
    for (int i = n - 2; i >= 0; i--) {
      while (!stk.empty() and a[i] >= a[stk.top()])
        stk.pop();
      int j = stk.empty() ? n : stk.top();
      st.rangeUpdate(1, i, j - 1, a[i]);

      int got = st.query(1, k);
      if (got == -1)
        got = i;

      ans += got - i + 1;
      stk.push(i);
    }
    return ans;
  }
};
