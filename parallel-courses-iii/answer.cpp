class Solution {
public:
  int minimumTime(int n, vector<vector<int>> &r, vector<int> &t) {
    vector<vector<int>> g(n);
    vector<int> indeg(n, 0);
    for (auto &edge : r) {
      int v = edge[0] - 1, u = edge[1] - 1;
      g[u].push_back(v);
      indeg[v] += 1;
    }

    vector<int> dp(n, -1);
    function<int(int)> dfs = [&](int u) -> int {
      if (dp[u] != -1)
        return dp[u];

      dp[u] = 0;
      for (int v : g[u])
        dp[u] = max(dp[u], dfs(v));
      return dp[u] += t[u];
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (indeg[i] == 0)
        ans = max(ans, dfs(i));
    }
    return ans;
  }
};
