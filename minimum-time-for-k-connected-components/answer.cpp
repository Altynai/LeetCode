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
  int minTime(int n, vector<vector<int>> &edges, int k) {
    dsu.init(n);
    int m = edges.size();
    for (int i = 0; i < m; i++) {
      dsu.join(edges[i][0], edges[i][1]);
    }
    if (dsu.components() >= k)
      return 0;

    sort(edges.begin(), edges.end(),
         [](const auto &lh, const auto &rh) { return lh[2] > rh[2]; });

    dsu.init(n);
    int ans = INT_MAX;
    for (int i = 0; i < m;) {
      if (dsu.components() >= k)
        ans = min(ans, edges[i][2]);
      int j = i;
      while (j < m and edges[i][2] == edges[j][2]) {
        dsu.join(edges[j][0], edges[j][1]);
        j++;
      }
      i = j;
    }
    return ans;
  }
};
