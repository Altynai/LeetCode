template <class T> int deduplicate(vector<T> &v) {
  sort(v.begin(), v.end());
  return v.erase(unique(v.begin(), v.end()), v.end()) - v.begin();
}

template <class T> struct Fenwick {
  vector<T> c;
  int n;

  Fenwick(int _n) {
    n = _n;
    c.resize(_n + 1);
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  inline int lowbit(int x) { return x & (-x); }

  void update(int x, T val) {
    for (int i = x; i <= n; i += lowbit(i))
      c[i] = max(val, c[i]);
  }

  T get(int x) {
    assert(0 <= x && x <= n);
    T ret = LLONG_MIN;
    for (int i = x; i > 0; i -= lowbit(i))
      ret = max(c[i], ret);
    return ret;
  }
};

using int64 = long long;

class Solution {
public:
  long long maxBalancedSubsequenceSum(vector<int> &a) {
    int n = a.size();
    vector<int> b(n);
    for (int i = 0; i < n; i++)
      b[i] = a[i] - i;

    int m = deduplicate(b);
    Fenwick<int64> fw(m);

    int64 ans = LLONG_MIN;
    for (int i = 0; i < n; i++) {
      int id = lower_bound(b.begin(), b.begin() + m, a[i] - i) - b.begin() + 1;
      int64 got = fw.get(id);
      int64 best = a[i];
      if (got != LLONG_MIN)
        best = max(best, got + a[i]);

      ans = max(ans, best);
      fw.update(id, best);
    }
    return ans;
  }
};
