template <class T> struct Fenwick {
  vector<T> c;
  int n;

  Fenwick(int _n) { init(_n); }

  void init(int _n) {
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

#define bitCount(n) __builtin_popcountll((n))

using int64 = long long;

class Solution {
public:
  vector<int> popcountDepth(vector<long long> &a,
                            vector<vector<long long>> &queries) {
    vector<int> cnt(65, 0);
    cnt[1] = 0;
    for (int i = 2; i <= 64; i++)
      cnt[i] = cnt[bitCount(i)] + 1;

    auto Get = [&](int64 x) -> int {
      if (x == 1)
        return 0;
      return cnt[bitCount(x)] + 1;
    };

    int n = a.size();
    vector<Fenwick<int>> fes(6, Fenwick<int>(n));
    for (int i = 0; i < n; i++) {
      int pos = Get(a[i]);
      if (pos < 6)
        fes[pos].update(i + 1, +1);
    }

    int q = queries.size();
    vector<int> ans;
    for (auto query : queries) {
      if (query[0] == 1) {
        int l = query[1] + 1, r = query[2] + 1, k = query[3];
        int res = fes[k].get(r) - fes[k].get(l - 1);
        ans.push_back(res);
      } else {
        int i = query[1];
        int pos = Get(a[i]);
        if (pos < 6)
          fes[pos].update(i + 1, -1);

        a[i] = query[2];
        pos = Get(a[i]);
        if (pos < 6)
          fes[pos].update(i + 1, +1);
      }
    }
    return ans;
  }
};
