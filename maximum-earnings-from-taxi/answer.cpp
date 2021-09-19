template <class T> struct Fenwick {

  vector<T> c;
  int n;

  Fenwick(int _n) {
    c.resize(_n + 1);
    n = _n;
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  void add(int x, T y) {
    for (; x <= n; x += x & -x)
      c[x] = std::max(c[x], y);
  }

  T max(int x) {
    assert(x <= n);
    T ret = 0;
    for (; x; x -= x & -x)
      ret = std::max(ret, c[x]);
    return ret;
  }
};

class Solution {
public:
  long long maxTaxiEarnings(int n, vector<vector<int>> &r) {
    int m = r.size();
    sort(r.begin(), r.end(), [&](const vector<int> &lh, const vector<int> &rh) {
      if (lh[1] != rh[1])
        return lh[1] < rh[1];
      return lh[0] < rh[0];
    });

    Fenwick<long long> fw(n);
    long long ans = 0;
    for (auto &t : r) {
      int s = t[0], e = t[1], tip = t[2];
      long long got = fw.max(s);
      long long earn = 1LL * (e - s) + tip;
      ans = max(ans, got + earn);
      fw.add(e, got + earn);
    }
    return ans;
  }
};
