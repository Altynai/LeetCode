template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

using int64 = long long;

class Solution {
public:
  long long maximumValueSum(vector<int> &nums, int k,
                            vector<vector<int>> &edges) {
    int n = nums.size();

    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<vector<int64>> dp(n, vector<int64>(2, -1));
    function<void(int, int)> dfs = [&](int u, int fa) {
      // leaf
      if (u != 0 and adj[u].size() == 1) {
        dp[u][0] = nums[u];
        return;
      }

      vector<int64> f(2, -1);
      f[0] = 0;

      for (auto v : adj[u]) {
        if (v == fa)
          continue;
        dfs(v, u);

        vector<int64> g(2, 0);
        for (int p = 0; p <= 1; p++) {
          if (dp[v][p] == -1)
            continue;

          for (int q = 0; q <= 1; q++) {
            if (f[q] == -1)
              continue;
            // flip u - v
            int64 val = dp[v][p] + (p == 0 ? -nums[v] + (nums[v] ^ k)
                                           : -(nums[v] ^ k) + nums[v]);
            umax(g[q ^ 1], f[q] + val);
            // do nothing
            umax(g[q], f[q] + dp[v][p]);
          }
        }
        swap(f, g);
      }
      umax(dp[u][0], f[0] + nums[u]);
      umax(dp[u][1], f[1] + (nums[u] ^ k));
    };

    dfs(0, -1);
    return max(dp[0][0], dp[0][1]);
  }
};
