struct DSU {
  int n;
  vector<int> p; // component parent

  void init(int _n) {
    n = _n;
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

  bool same(int x, int y) { return find(x) == find(y); }

  bool join(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)
      return 0;

    if (x < y)
      swap(x, y);
    p[y] = x;
    return 1;
  }
} dsu;

class Solution {
public:
  long long countPairs(int n, vector<vector<int>> &edges) {
    dsu.init(n);
    for (auto &e : edges)
      dsu.join(e[0], e[1]);

    map<int, int> cnt;
    for (int i = 0; i < n; i++)
      cnt[dsu.find(i)]++;

    long long ans = 1LL * n * (n - 1);
    for (auto [k, v] : cnt)
      ans -= 1LL * v * (v - 1);
    return ans / 2;
  }
};
