const int N = 14;

class Solution {
public:
  int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    // dp[i][j]: maximum sum in sub-tree rooted at i, with j times of "floor"
    // options from ancestors
    vector<vector<int>> dp(n, vector<int>(N, 0));
    function<void(int, int)> dfs = [&](int u, int fa) {
      // leaf
      if (u != 0 and adj[u].size() == 1) {
        for (int i = 0; i < N; i++)
          dp[u][i] = max((coins[u] >> i) - k, coins[u] >> (i + 1));
        return;
      }

      for (int v : adj[u]) {
        if (v == fa)
          continue;
        dfs(v, u);
      }

      for (int i = 0; i < N; i++) {
        // option 1
        int sum = 0;
        for (int v : adj[u]) {
          if (v == fa)
            continue;
          sum += dp[v][i];
        }
        dp[u][i] = (coins[u] >> i) - k + sum;

        // option 2
        sum = 0;
        if (i + 1 < N) {
          for (int v : adj[u]) {
            if (v == fa)
              continue;
            sum += dp[v][i + 1];
          }
          dp[u][i] = max(dp[u][i], (coins[u] >> (i + 1)) + sum);
        }
      }
    };
    dfs(0, -1);
    return max(dp[0][0], dp[0][1]);
  }
};
