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
  int minScore(int n, vector<vector<int>> &roads) {
    dsu.init(n);
    for (auto &road : roads) {
      int u = road[0] - 1, v = road[1] - 1, w = road[2];
      int ru = dsu.find(u);
      int rv = dsu.find(v);
      if (ru != rv)
        dsu.join(u, v);
    }

    int ans = INT_MAX, root = dsu.find(0);
    for (auto &road : roads) {
      int u = road[0] - 1, w = road[2];
      if (dsu.find(u) == root)
        ans = min(ans, w);
    }
    return ans;
  }
};
