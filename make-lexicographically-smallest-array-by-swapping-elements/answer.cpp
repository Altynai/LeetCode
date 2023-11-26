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
  vector<int> lexicographicallySmallestArray(vector<int> &a, int limit) {
    int n = a.size();
    dsu.init(n);

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
      p[i] = {a[i], i};
    sort(p.begin(), p.end());

    for (int i = 1; i < n; i++) {
      if (p[i].first - p[i - 1].first <= limit) {
        dsu.join(p[i].second, p[i - 1].second);
      }
    }

    unordered_map<int, vector<int>> g;
    for (int i = 0; i < n; i++)
      g[dsu.find(i)].push_back(i);

    vector<int> ans(n);
    for (auto &[_, ids] : g) {
      vector<int> vals;
      for (int x : ids)
        vals.push_back(a[x]);
      sort(vals.begin(), vals.end());

      int m = ids.size();
      for (int i = 0; i < m; i++)
        ans[ids[i]] = vals[i];
    }
    return ans;
  }
};
