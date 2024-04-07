struct DSU {
  int n;
  vector<int> p; // component parent
  vector<int> s; // size

  void init(int _n) {
    n = _n;
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
    return 1;
  }
} dsu;

class Solution {
public:
  vector<int> minimumCost(int n, vector<vector<int>> &edges,
                          vector<vector<int>> &query) {
    dsu.init(n);
    int m = edges.size();
    for (int i = 0; i < m; i++) {
      int u = edges[i][0], v = edges[i][1];
      dsu.join(u, v);
    }

    unordered_map<int, int> vals;
    for (int i = 0; i < m; i++) {
      int u = edges[i][0], v = edges[i][1];
      int root = dsu.find(u);
      if (vals.find(root) != vals.end())
        vals[root] &= edges[i][2];
      else
        vals[root] = edges[i][2];
    }

    int q = query.size();
    vector<int> ans(q, -1);
    for (int i = 0; i < q; i++) {
      int u = query[i][0], v = query[i][1];
      if (u == v)
        ans[i] = 0;
      else if (dsu.same(u, v))
        ans[i] = vals[dsu.find(u)];
    }

    return ans;
  }
};
