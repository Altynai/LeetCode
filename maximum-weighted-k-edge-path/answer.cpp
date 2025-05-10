const int N = 601;

class Solution {
public:
  int maxWeight(int n, vector<vector<int>> &edges, int k, int t) {
    int m = edges.size();
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
      int u = edges[i][0], v = edges[i][1], w = edges[i][2];
      adj[u].push_back({v, w});
    }

    // dp[i][j] = bitset<600>
    // possible sums formed by j paths started from sub-graph of node i
    vector<bool> vis(n, 0);
    vector<vector<bitset<N>>> dp(n, vector<bitset<N>>(k + 1, 0));

    function<void(int)> dfs = [&](int u) {
      if (vis[u])
        return;

      vis[u] = 1;
      dp[u][0].set(0, 1);

      if (adj[u].size() == 0)
        return;

      for (auto [v, w] : adj[u])
        dfs(v);

      for (int i = 1; i <= k; i++) {
        for (auto [v, w] : adj[u]) {
          dp[u][i] |= (dp[v][i - 1] << w);
        }
      }
    };

    int ans = -1;
    for (int i = 0; i < n; i++) {
      dfs(i);
      for (int j = 0; j < t; j++) {
        if (dp[i][k].test(j))
          ans = max(ans, j);
      }
    }
    return ans;
  }
};
