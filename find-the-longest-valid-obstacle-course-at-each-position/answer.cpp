struct fenwick {
#define T int

  vector<T> c;
  int n;

  void init(int _n) {
    c.resize(_n + 1);
    n = _n;
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  void update(int x, T y) {
    for (; x <= n; x += x & -x)
      c[x] = std::max(c[x], y);
  }

  T query(int x) {
    assert(x <= n);
    T ret = 0;
    for (; x; x -= x & -x)
      ret = std::max(ret, c[x]);
    return ret;
  }
} fw;

class Solution {
public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int> &a) {
    int n = a.size();
    vector<int> b(a);
    sort(b.begin(), b.end());
    int m = unique(b.begin(), b.end()) - b.begin();
    b.resize(m);
    for (int i = 0; i < n; i++)
      a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();

    fw.init(n);
    vector<int> ans(n, 1);
    for (int i = 0; i < n; i++) {
      int best = fw.query(a[i] + 1);
      ans[i] = max(ans[i], best + 1);
      fw.update(a[i] + 1, ans[i]);
    }
    return ans;
  }
};
