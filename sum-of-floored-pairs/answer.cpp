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
    x = min(x, n);
    T ret = 0;
    for (; x; x -= x & -x)
      ret += c[x];
    return ret;
  }
} fw;

class Solution {
public:
  int sumOfFlooredPairs(vector<int> &a) {
    map<int, int> cnt;
    for (int v : a)
      cnt[v]++;
    int maxn = cnt.rbegin()->first;
    fw.init(maxn);

    const int MOD = 1e9 + 7;
    int ans = 0;

    vector<int> b;
    for (auto [k, v] : cnt) {
      b.push_back(k);
      fw.add(k, v);
    }

    int n = b.size();
    for (int i = 0; i < n; i++) {
      int x = cnt[b[i]];
      ans += 1LL * x * x % MOD;
      ans %= MOD;

      for (int k = b[i]; k <= maxn; k += b[i]) {
        int r = k + b[i] - 1;
        int l = (k == b[i] ? b[i] : k - 1);
        int y = fw.sum(r) - fw.sum(l);
        ans += 1LL * (k / b[i]) * x * y % MOD;
        ans %= MOD;
      }
    }
    return ans;
  }
};
