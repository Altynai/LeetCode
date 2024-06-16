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
      c[i] = c[i] + val;
  }

  // sum of [1 ... x]
  T get(int x) {
    assert(0 <= x && x <= n);
    T ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
      ret = ret + c[i];
    return ret;
  }
};

class Solution {
public:
  vector<int> countOfPeaks(vector<int> &a, vector<vector<int>> &queries) {
    int n = a.size();

    auto IsPeak = [&](int x) -> bool {
      if (x == 1 or x == n)
        return 0;
      return a[x - 2] < a[x - 1] and a[x - 1] > a[x];
    };

    Fenwick<int> bits(n);
    for (int i = 2; i < n; i++) {
      if (IsPeak(i))
        bits.update(i, 1);
    }

    int m = queries.size();
    vector<int> ans;
    for (int i = 0; i < m; i++) {
      if (queries[i][0] == 1) {
        int l = queries[i][1] + 1;
        int r = queries[i][2] + 1;
        int res = 0;
        if (r - l >= 2)
          res = bits.get(r - 1) - bits.get(l);
        ans.push_back(res);
      } else {
        int pos = queries[i][1] + 1;
        for (int j = max(2, pos - 1); j <= min(n - 1, pos + 1); j++) {
          if (IsPeak(j))
            bits.update(j, -1);
        }
        a[pos - 1] = queries[i][2];
        for (int j = max(2, pos - 1); j <= min(n - 1, pos + 1); j++) {
          if (IsPeak(j))
            bits.update(j, 1);
        }
      }
    }
    return ans;
  }
};
