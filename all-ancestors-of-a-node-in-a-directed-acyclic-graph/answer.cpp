class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
    vector<vector<int>> g(n);
    for (auto &e : edges)
      g[e[1]].push_back(e[0]);

    vector<vector<int>> ans(n);
    vector<bool> vis(n, 0);

    function<void(int)> dfs = [&](int u) {
      if (vis[u])
        return;

      vis[u] = 1;
      set<int> ids;
      for (int v : g[u]) {
        dfs(v);
        ids.insert(v);
        for (int x : ans[v])
          ids.insert(x);
      }
      ans[u] = vector<int>(ids.begin(), ids.end());
    };

    for (int i = 0; i < n; i++)
      dfs(i);
    return ans;
  }
};
