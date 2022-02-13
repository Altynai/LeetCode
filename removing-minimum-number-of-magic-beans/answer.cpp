// 1d BIT: 单点增加，区间查询
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

  T range(int l, int r) {
    if (l > r)
      return 0;
    return sum(r) - sum(l - 1);
  }
};

class Solution {
public:
  long long minimumRemoval(vector<int> &a) {
    int n = a.size();
    sort(a.begin(), a.end());

    const int N = a.back();
    Fenwick<int> cnt(N);
    Fenwick<long long> sum(N);

    for (int i = n - 1; i >= 0; i--) {
      cnt.add(a[i], 1);
      sum.add(a[i], 1LL * a[i]);
    }

    long long ans = LLONG_MAX;
    for (int i = n - 1; i >= 0; i--) {
      long long s = sum.range(a[i] + 1, N);
      long long c = cnt.range(a[i] + 1, N);
      long long cost = s - c * a[i];
      cost += sum.range(1, a[i] - 1);

      ans = min(ans, cost);
    }
    return ans;
  }
};
