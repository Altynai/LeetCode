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
  int maxChunksToSorted(vector<int> &a) {
    int n = a.size();
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++)
      b[i].first = a[i], b[i].second = i;

    sort(b.begin(), b.end());
    vector<int> p(n);
    for (int i = 0; i < n; i++)
      p[b[i].second] = i;

    Fenwick<int> bits(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      bits.add(p[i] + 1, 1);
      int pos = i + 1;
      if (bits.sum(pos) == pos and bits.sum(n) == pos)
        ans++;
    }
    return ans;
  }
};
