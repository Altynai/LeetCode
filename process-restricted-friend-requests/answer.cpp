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

  int find(int x) {
    int r = x;
    while (p[r] != r)
      r = p[r];
    for (int i = x; p[i] != r;) {
      int j = p[i];
      p[i] = r;
      i = j;
    }
    return r;
  }

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
  vector<bool> friendRequests(int n, vector<vector<int>> &res,
                              vector<vector<int>> &reqs) {
    dsu.init(n);

    int m = reqs.size();
    set<pair<int, int>> edges;

    vector<bool> ans(m, false);
    for (int k = 0; k < m; k++) {
      int u = reqs[k][0], v = reqs[k][1];
      int ru = dsu.find(u), rv = dsu.find(v);

      bool ok = true;
      for (int i = 0; ok && i < res.size(); i++) {
        // if we connect u-v, ru-rv will be connect
        int x = dsu.find(res[i][0]);
        int y = dsu.find(res[i][1]);
        if (dsu.same(x, ru) && dsu.same(y, rv))
          ok = false;
        if (dsu.same(x, rv) && dsu.same(y, ru))
          ok = false;
      }
      ans[k] = ok;
      if (ok)
        dsu.join(u, v);
    }
    return ans;
  }
};
