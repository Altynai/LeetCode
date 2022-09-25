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
  int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
    int n = vals.size();

    map<int, vector<int>> nodes;
    for (int i = 0; i < n; i++)
      nodes[vals[i]].push_back(i);

    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    dsu.init(n);
    int ans = n;
    for (auto &[val, ids] : nodes) {
      for (int x : ids) {
        for (int y : adj[x]) {
          if (vals[y] <= val)
            dsu.join(x, y);
        }
      }
      unordered_map<int, int> groups;
      for (int x : ids)
        groups[dsu.find(x)]++;
      for (auto [k, v] : groups)
        ans += v * (v - 1) / 2;
    }
    return ans;
  }
};
