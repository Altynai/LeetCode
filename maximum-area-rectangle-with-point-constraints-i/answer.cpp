template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

struct WaveletTree {
  int low, high;
  WaveletTree *l, *r;
  vector<int> b;

  // array indices are [from, to), values are [x, y]
  // NOTE: from, to: doesn't matter if using 0 or 1 based index
  WaveletTree(vector<int> &v, int from, int to, int x, int y) {
    low = x, high = y;
    if (low == high or from >= to)
      return;
    int mid = (low + high) / 2;
    auto f = [mid](int x) { return x <= mid; };
    b.reserve(to - from + 1);
    b.push_back(0);
    for (int i = from; i != to; i++)
      b.push_back(b.back() + f(v[i]));

    int pivot =
        stable_partition(v.begin() + from, v.begin() + to, f) - v.begin();
    l = new WaveletTree(v, from, pivot, low, mid);
    r = new WaveletTree(v, pivot, to, mid + 1, high);
  }

  // kth smallest element in [l, r]
  // NOTE: l, r are 1-based index
  int kth(int l, int r, int k) {
    if (l > r)
      return 0;
    if (low == high)
      return low;
    int inLeft = b[r] - b[l - 1];
    int lb = b[l - 1]; // amt of nos in first (l-1) nos that go in left
    int rb = b[r];     // amt of nos in first (r) nos that go in left
    if (k <= inLeft)
      return this->l->kth(lb + 1, rb, k);
    return this->r->kth(l - lb, r - rb, k - inLeft);
  }

  // count of numbers in [l, r] less than or equal to k
  // NOTE: l, r are 1-based index
  int lessThanOrEqual(int l, int r, int k) {
    if (l > r or k < low)
      return 0;
    if (high <= k)
      return r - l + 1;
    int lb = b[l - 1], rb = b[r];
    return this->l->lessThanOrEqual(lb + 1, rb, k) +
           this->r->lessThanOrEqual(l - lb, r - rb, k);
  }

  // count of numbers in [l, r] equal to k
  // NOTE: l, r are 1-based index
  int count(int l, int r, int k) {
    if (l > r or k < low or k > high)
      return 0;
    if (low == high)
      return r - l + 1;
    int lb = b[l - 1], rb = b[r], mid = (low + high) / 2;
    if (k <= mid)
      return this->l->count(lb + 1, rb, k);
    return this->r->count(l - lb, r - rb, k);
  }
};

class Solution {
public:
  int maxRectangleArea(vector<vector<int>> &coordinates) {
    // since we can not have points on its border, for the same X, we can only
    // choose two adjacent Y's as one of the edges.
    // then same case for two adjacent X's

    // so assume left down corner is (X0, Y0), the left up corner is (X0, Y1)
    // we need to find the next X which contains both Y0 and Y1
    // this can be done via a reversed map: key is pair<Y0, Y1>, value is a list
    // of valid X's

    // so now let's say we've found another X1, how we check "no any other point
    // inside"? for any X (X0 < X < X1), there should not be any Y satisfies Y0
    // <= Y <= Y1 seems related to 2d binary index tree? but can get MLE then we
    // can sort all (X, Y) pairs, finding Y can be converted into a range query
    // in wavelet tree

    vector<int> uniqy;
    for (auto co : coordinates)
      uniqy.push_back(co[1]);
    int m = deduplicate(uniqy);

    int n = coordinates.size();
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
      int idx = lower_bound(uniqy.begin(), uniqy.end(), coordinates[i][1]) -
                uniqy.begin();
      points[i] = {coordinates[i][0], idx};
    }

    map<pair<int, int>, int> last_seen;

    sort(points.begin(), points.end());
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      v[i] = points[i].second;
    WaveletTree *root = new WaveletTree(v, 0, n, 0, m - 1);

    int ans = -1;

    for (int i = 0, j; i < n; i = j) {
      j = i + 1;
      while (j < n and points[j - 1].first == points[j].first)
        j++;

      int x1 = points[i].first;
      int R = lower_bound(points.begin(), points.end(), make_pair(x1, 0)) -
              points.begin() - 1;

      for (int k = i + 1; k < j; k++) {
        int y0 = points[k - 1].second, y1 = points[k].second;
        int ylen = uniqy[y1] - uniqy[y0];

        auto it = last_seen.find({y0, y1});
        if (it == last_seen.end())
          continue;
        int x0 = it->second;

        // find range for wavelet tree query
        int L =
            lower_bound(points.begin(), points.end(), make_pair(x0 + 1, 0)) -
            points.begin();
        if (L == n)
          continue;

        if (L > R)
          umax(ans, (x1 - x0) * ylen);
        else if (root->lessThanOrEqual(L + 1, R + 1, y1) ==
                 root->lessThanOrEqual(L + 1, R + 1, y0 - 1))
          umax(ans, (x1 - x0) * ylen);
      }

      for (int k = i + 1; k < j; k++) {
        int y0 = points[k - 1].second, y1 = points[k].second;
        last_seen[{y0, y1}] = x1;
      }
    }
    return ans;
  }
};
