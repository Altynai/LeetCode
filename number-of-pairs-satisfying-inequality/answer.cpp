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

  void add(int x, T val) {
    for (int i = x; i <= n; i += lowbit(i))
      c[i] += val;
  }

  // sum of [1 ... x]
  T sum(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      ret += c[i];
    return ret;
  }
};

class Solution {
public:
  long long numberOfPairs(vector<int> &a, vector<int> &b, int diff) {
    int n = a.size();
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
      c[i] = a[i] - b[i];
    }

    vector<int> d = c;
    int m = deduplicate(d);
    Fenwick<int> fw(m);

    long long ans = 0;
    for (int j = 0; j < n; j++) {
      int x = c[j] + diff;
      int idx = lower_bound(d.begin(), d.end(), x + 1) - d.begin();
      ans += fw.sum(idx);
      idx = lower_bound(d.begin(), d.end(), c[j]) - d.begin() + 1;
      fw.add(idx, 1);
    }
    return ans;
  }
};
