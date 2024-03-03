class Solution {
public:
  vector<int> countPairsOfConnectableServers(vector<vector<int>> &edges,
                                             int signalSpeed) {
    int n = edges.size() + 1;
    vector<vector<pair<int, int>>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back({e[1], e[2]});
      adj[e[1]].push_back({e[0], e[2]});
    }

    vector<int> cnt(n, 0);
    function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
      cnt[u] = 0;
      if (d % signalSpeed == 0)
        cnt[u]++;
      for (auto [v, w] : adj[u]) {
        if (v == fa)
          continue;
        dfs(v, u, d + w);
        cnt[u] += cnt[v];
      }
    };

    vector<int> ans(n, 0);
    for (int u = 0; u < n; u++) {
      dfs(u, -1, 0);

      vector<int> p;
      for (auto [v, w] : adj[u]) {
        if (cnt[v] > 0)
          p.push_back(cnt[v]);
      }
      int total = accumulate(p.begin(), p.end(), 0);
      for (int x : p) {
        total -= x;
        ans[u] += x * total;
      }
    }
    return ans;
  }
};
