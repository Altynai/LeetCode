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

  int components() {
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(find(i));
    return s.size();
  }

} dsu;

class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &a, int maxDiff,
                                    vector<vector<int>> &queries) {
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
      v[i] = {a[i], i};
    sort(v.begin(), v.end());

    dsu.init(n);
    for (int i = 1; i < n; i++) {
      if (v[i].first - v[i - 1].first <= maxDiff) {
        dsu.join(v[i].second, v[i - 1].second);
      }
    }

    int m = queries.size();
    vector<bool> ans(m);
    for (int i = 0; i < m; i++) {
      int u = queries[i][0], v = queries[i][1];
      ans[i] = dsu.same(u, v);
    }
    return ans;
  }
};
