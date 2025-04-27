const int MOD = 1e9 + 7;

class Solution {
public:
  vector<int> baseUnitConversions(vector<vector<int>> &conversions) {
    int n = conversions.size() + 1;
    vector<vector<pair<int, int>>> adj(n);
    for (auto c : conversions) {
      int u = c[0], v = c[1], w = c[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    vector<int> dp(n, 1);
    function<void(int, int)> dfs = [&](int u, int fa) {
      for (auto [v, w] : adj[u]) {
        if (v == fa)
          continue;
        dp[v] = 1LL * dp[u] * w % MOD;
        dfs(v, u);
      }
    };
    dfs(0, -1);
    return dp;
  }
};
