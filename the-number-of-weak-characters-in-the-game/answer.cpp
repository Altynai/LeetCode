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

  void add(int x, T y) {
    for (; x <= n; x += x & -x)
      c[x] += y;
  }

  T sum(int x) {
    assert(x <= n);
    T ret = 0;
    for (; x; x -= x & -x)
      ret += c[x];
    return ret;
  }
} fw;

class Solution {
public:
  int numberOfWeakCharacters(vector<vector<int>> &p) {
    sort(p.begin(), p.end());
    int n = p.size();

    const int maxn = 1e5;
    fw.init(maxn);
    int ans = 0;

    for (int i = n - 1; i >= 0;) {
      int j = i;
      while (j >= 0 && p[j][0] == p[i][0])
        j--;

      for (int k = i; k > j; k--) {
        if (fw.sum(maxn) - fw.sum(p[k][1]) > 0)
          ans++;
      }

      for (int k = i; k > j; k--)
        fw.add(p[k][1], 1);
      i = j;
    }

    return ans;
  }
};
