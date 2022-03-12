class Solution {
public:
  vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
    int m = edges.size();
    int n = m;
    vector<int> indeg(n, 0);
    vector<vector<int>> g(n);
    for (auto &e : edges) {
      e[0]--, e[1]--;
      g[e[0]].push_back(e[1]);
      indeg[e[1]]++;
    }

    vector<bool> vis(n, 0);
    int k = m - 1, cnt = 0;

    function<void(int)> dfs = [&](int u) {
      vis[u] = 1;
      cnt++;
      for (int v : g[u]) {
        if (u == edges[k][0] and v == edges[k][1])
          continue;
        if (!vis[v])
          dfs(v);
      }
    };

    for (k = m - 1; k >= 0; k--) {
      int u = edges[k][0], v = edges[k][1];
      cnt = 0;
      vis.assign(n, 0);
      indeg[v]--;

      int p =
          find_if(indeg.begin(), indeg.end(), [](int x) { return x == 0; }) -
          indeg.begin();
      assert(p != n);
      dfs(p);
      indeg[v]++;

      if (cnt == n)
        return {u + 1, v + 1};
    }
    return {};
  }
};
