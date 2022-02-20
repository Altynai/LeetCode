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
};

class Solution {
public:
  long long goodTriplets(vector<int> &a, vector<int> &b) {
    int n = a.size();

    vector<int> pa(n), pb(n);
    for (int i = 0; i < n; i++)
      pa[a[i]] = pb[b[i]] = i;

    vector<pair<int, int>> pos;
    for (int i = 0; i < n; i++)
      pos.push_back({pa[i], pb[i]});
    sort(pos.begin(), pos.end());

    Fenwick<int> fw(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      int x = pos[i].second + 1;
      int less = fw.sum(x - 1);
      ans += 1LL * less * (n - x - (i - less));
      fw.add(x, 1);
    }
    return ans;
  }
};
