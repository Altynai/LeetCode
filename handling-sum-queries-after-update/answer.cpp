using int64 = long long;

struct LazySegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  const static int MAXN = 100004 << 2;

  // basic fields
  int L[MAXN], R[MAXN];

  // maintained fields
  int tag[MAXN];
  int cnt[MAXN][2];

  inline int rangeSize(int p) { return R[p] - L[p] + 1; }

  void build(int p, int l, int r, vector<int> &a) {
    L[p] = l, R[p] = r;
    tag[p] = -1;
    cnt[p][0] = cnt[p][1] = 0;

    if (l == r) {
      cnt[p][a[l]]++;
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid, a);
      build(rson(p), mid + 1, r, a);
      pull(p);
    }
  }

  void tagNode(int p, int val) {
    if (tag[p] == -1)
      tag[p] = val;
    else {
      tag[p] += val;
      tag[p] %= 2;
    }
  }

  void push(int p) {
    // can't push down on leaf nodes
    assert(L[p] != R[p]);
    if (tag[p] != -1) {
      tagNode(lson(p), tag[p]);
      tagNode(rson(p), tag[p]);
    }
    tag[p] = -1;
  }

  void pull(int p) {
    // can't pull on leaf nodes
    assert(L[p] != R[p]);
    bool tagged_l = (tag[lson(p)] == 1);
    bool tagged_r = (tag[rson(p)] == 1);

    cnt[p][0] = cnt[lson(p)][tagged_l ? 1 : 0] + cnt[rson(p)][tagged_r ? 1 : 0];
    cnt[p][1] = cnt[lson(p)][tagged_l ? 0 : 1] + cnt[rson(p)][tagged_r ? 0 : 1];
  }

  void rangeAdd(int p, int l, int r, int val) {
    // case 1: covers the entire range
    if (L[p] == l && R[p] == r) {
      tagNode(p, val);
    }
    // case 2: may need to split the range
    else {
      // make sure to call push before doing rangeSet on child nodes
      push(p);
      int mid = (L[p] + R[p]) >> 1;
      if (r <= mid)
        rangeAdd(lson(p), l, r, val);
      else if (l > mid)
        rangeAdd(rson(p), l, r, val);
      else {
        rangeAdd(lson(p), l, mid, val);
        rangeAdd(rson(p), mid + 1, r, val);
      }
      // make sure to call pull after doing rangeSet on child nodes
      pull(p);
    }
  }

  int query(int p, int l, int r) {
    // case 1: covers the entire range
    if (L[p] == l && R[p] == r) {
      return cnt[p][(tag[p] == 1) ? 0 : 1];
    }
    // case 2: may need to split the range
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
  vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2,
                                vector<vector<int>> &queries) {
    int n = nums1.size();
    st.build(1, 0, n - 1, nums1);

    int64 sum = accumulate(nums2.begin(), nums2.end(), 0LL);
    vector<int64> ans;
    for (auto q : queries) {
      if (q[0] == 1)
        st.rangeAdd(1, q[1], q[2], 1);
      else if (q[0] == 2)
        sum += 1LL * st.query(1, 0, n - 1) * q[1];
      else
        ans.push_back(sum);
    }
    return ans;
  }
};
