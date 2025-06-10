template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxProfit(int n, vector<int> &present, vector<int> &future,
                vector<vector<int>> &hierarchy, int budget) {
    // dp[i][0][budget]: max profit with budget if parent has NOT bought stock
    // dp[i][1][budget]: max profit with budget if parent has bought stock

    vector<vector<int>> adj(n);
    for (auto edge : hierarchy)
      adj[edge[0] - 1].push_back(edge[1] - 1);

    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(2, vector<int>(budget + 1, INT_MIN)));
    function<void(int)> dfs = [&](int u) {
      if (adj[u].size() == 0) {
        for (int i = 0; i <= budget; i++)
          dp[u][0][i] = dp[u][1][i] = 0;
      }

      for (int v : adj[u])
        dfs(v);

      for (int flag = 0; flag <= 1; flag++) { // if parent has bought
        int price = (flag == 1 ? present[u] / 2 : present[u]);
        int profit = future[u] - price;

        // knapsack
        vector<int> ks(budget + 1, INT_MIN);

        // don't buy u
        ks[0] = 0;
        for (int v : adj[u]) {
          vector<int> ks2(budget + 1, INT_MIN);
          for (int b1 = 0; b1 <= budget; b1++) {
            if (ks[b1] == INT_MIN)
              continue;
            for (int b2 = 0; b1 + b2 <= budget; b2++) {
              if (dp[v][0][b2] == INT_MIN)
                continue;
              umax(ks2[b1 + b2], ks[b1] + dp[v][0][b2]);
            }
          }
          swap(ks, ks2);
        }
        for (int i = 0; i <= budget; i++)
          umax(dp[u][flag][i], ks[i]);

        // buy u
        if (price <= budget) {
          ks.assign(budget + 1, INT_MIN);
          ks[0] = 0;

          for (int v : adj[u]) {
            vector<int> ks2(budget + 1, INT_MIN);
            for (int b1 = 0; b1 <= budget; b1++) {
              if (ks[b1] == INT_MIN)
                continue;
              for (int b2 = 0; b1 + b2 <= budget; b2++) {
                if (dp[v][1][b2] == INT_MIN)
                  continue;
                umax(ks2[b1 + b2], ks[b1] + dp[v][1][b2]);
              }
            }
            swap(ks, ks2);
          }

          for (int i = price; i <= budget; i++) {
            if (ks[i - price] == INT_MIN)
              continue;
            umax(dp[u][flag][i], ks[i - price] + profit);
          }
        }
      }
    };
    dfs(0);
    return *max_element(dp[0][0].begin(), dp[0][0].end());
  }
};
