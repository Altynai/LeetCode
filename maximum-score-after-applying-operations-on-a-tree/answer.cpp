using int64 = long long;

class Solution {
public:
  long long maximumScoreAfterOperations(vector<vector<int>> &edges,
                                        vector<int> &values) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<vector<int64>> dp(n, vector<int64>(2, 0));
    function<void(int, int)> dfs = [&](int u, int fa) {
      // leaf
      if (u != 0 and adj[u].size() == 1) {
        dp[u][1] = 0;
        dp[u][0] = values[u];
        return;
      }

      for (int v : adj[u]) {
        if (v == fa)
          continue;
        dfs(v, u);
      }

      int64 healthy = 0;
      // case 1: remove node u and add it the score
      // subtree u is healthy only if its descendants are healthy
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        healthy += dp[v][1];
      }
      dp[u][1] = healthy + values[u];

      // subtree u is not healthy if at least one of its descendants is not
      // healthy
      int64 sum = 0;
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        sum += max(dp[v][0], dp[v][1]);
      }
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        int64 cur = max(dp[v][0], dp[v][1]);
        dp[u][0] = max(dp[u][0], sum - cur + dp[v][0] + values[u]);
      }

      // case 2: keep node u
      // all the subtrees will be healthy
      dp[u][1] = max(sum, dp[u][1]);
    };

    dfs(0, -1);
    return dp[0][1];
  }
};
