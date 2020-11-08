struct fenwick {
#define T int
#define max_m 100005

  T c[max_m];
  int n;

  void init(int _n) {
    n = _n;
    for (int i = 1; i <= n; i++)
      c[i] = 0;
  }

  void add(int x, T y) {
    for (; x <= n; x += x & -x)
      c[x] += y;
  }

  T sum(int x) {
    T ret = 0;
    for (; x; x -= x & -x)
      ret += c[x];
    return ret;
  }
} fw;

class Solution {
public:
  int createSortedArray(vector<int> &a) {
    int n = a.size();
    int m = *max_element(a.begin(), a.end());
    fw.init(m + 1);

    int ans = 0;
    int mod = 1e9 + 7;

    for (int i = 0; i < n; i++) {
      ans += min(fw.sum(a[i] - 1), fw.sum(m) - fw.sum(a[i]));
      ans %= mod;
      fw.add(a[i], 1);
    }
    return ans;
  }
};
