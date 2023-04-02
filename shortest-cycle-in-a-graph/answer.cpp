class Solution {
public:
  int findShortestCycle(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<int> depth(n, -1);
    int ans = INT_MAX;

    function<void(int, int)> dfs = [&](int u, int d) {
      depth[u] = d;
      for (int v : adj[u]) {
        if (depth[v] == -1)
          dfs(v, d + 1);
        else if (depth[v] < d - 1)
          ans = min(ans, d - depth[v] + 1);
      }
    };

    for (int i = 0; i < n; i++) {
      depth.assign(n, -1);
      dfs(i, 0);
    }
    if (ans == INT_MAX)
      ans = -1;
    return ans;
  }
};
