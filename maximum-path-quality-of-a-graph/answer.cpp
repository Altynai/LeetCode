class Solution {
public:
  int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges,
                         int maxTime) {
    int n = values.size();

    vector<vector<pair<int, int>>> g(n);
    for (auto &e : edges) {
      g[e[0]].emplace_back(e[1], e[2]);
      g[e[1]].emplace_back(e[0], e[2]);
    }

    vector<bool> vis(n, false);
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int u, int time, int sum) {
      bool changed = false;
      if (!vis[u]) {
        changed = vis[u] = true;
        sum += values[u];
      }
      if (u == 0)
        ans = max(ans, sum);

      for (auto [v, cost] : g[u]) {
        if (time + cost <= maxTime)
          dfs(v, time + cost, sum);
      }

      if (changed) {
        vis[u] = false;
        sum -= values[u];
      }
    };
    dfs(0, 0, 0);
    return ans;
  }
};
