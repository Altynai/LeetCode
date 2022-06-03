#define int64 long long

struct SegmentTree {
#define lson(p) (p << 1)
#define rson(p) ((p << 1) | 1)

  static const int MAXN = 100004 << 2;

  int L[MAXN], R[MAXN], m;

  int64 sum[MAXN];
  int ma[MAXN];

  void build(int p, int l, int r) {
    L[p] = l, R[p] = r;
    if (l == r) {
      sum[p] = ma[p] = m;
    } else {
      int mid = (l + r) >> 1;
      build(lson(p), l, mid);
      build(rson(p), mid + 1, r);
      pull(p);
    }
  }

  void pull(int p) {
    sum[p] = sum[lson(p)] + sum[rson(p)];
    ma[p] = max(ma[lson(p)], ma[rson(p)]);
  }

  int getMax(int p, int l, int r) {
    if (L[p] == l && R[p] == r)
      return ma[p];
    int mid = (L[p] + R[p]) >> 1;
    if (r <= mid)
      return getMax(lson(p), l, r);
    else if (l > mid)
      return getMax(rson(p), l, r);
    else {
      return max(getMax(lson(p), l, mid), getMax(rson(p), mid + 1, r));
    }
  }

  vector<int> fillGather(int p, int k) {
    if (L[p] == R[p]) {
      vector<int> ans = {L[p], m - ma[p]};
      ma[p] -= k;
      sum[p] -= k;
      return ans;
    }

    vector<int> res;
    if (ma[lson(p)] >= k)
      res = fillGather(lson(p), k);
    else
      res = fillGather(rson(p), k);
    pull(p);
    return res;
  }

  int64 getSum(int p, int l, int r) {
    if (L[p] == l && R[p] == r)
      return sum[p];
    int mid = (L[p] + R[p]) >> 1;
    if (r <= mid)
      return getSum(lson(p), l, r);
    else if (l > mid)
      return getSum(rson(p), l, r);
    else {
      return getSum(lson(p), l, mid) + getSum(rson(p), mid + 1, r);
    }
  }

  void fillScatter(int p, int &k) {
    if (L[p] == R[p]) {
      int d = min(k, ma[p]);
      ma[p] -= d;
      sum[p] -= d;
      k -= d;
      return;
    }

    if (k > 0)
      fillScatter(lson(p), k);
    if (k > 0)
      fillScatter(rson(p), k);
    pull(p);
  }

} st;

class BookMyShow {
  int n;

public:
  BookMyShow(int n, int m) {
    this->n = n;
    st.m = m;
    st.build(1, 0, n - 1);
  }

  vector<int> gather(int k, int maxRow) {
    int ma = st.getMax(1, 0, maxRow);
    if (ma < k)
      return {};
    return st.fillGather(1, k);
  }

  bool scatter(int k, int maxRow) {
    int64 sum = st.getSum(1, 0, maxRow);
    if (sum < k)
      return false;
    st.fillScatter(1, k);
    return true;
  }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
