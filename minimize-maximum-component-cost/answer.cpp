struct DSU {
  int n, cnt;
  vector<int> p; // component parent
  vector<int> s; // size

  void init(int _n) {
    cnt = n = _n;
    p.resize(n);
    s.resize(n);
    s.assign(n, 1);
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
    s[x] += s[y];
    cnt--;
    return 1;
  }

  int components() { return cnt; }

} dsu;

class Solution {
public:
  int minCost(int n, vector<vector<int>> &edges, int k) {
    int ans = -1;
    for (int l = 0, r = 1e6; l <= r;) {
      int mid = (l + r) / 2;
      dsu.init(n);
      for (auto e : edges) {
        if (e[2] > mid)
          continue;
        else
          dsu.join(e[0], e[1]);
      }
      if (dsu.components() <= k)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};
