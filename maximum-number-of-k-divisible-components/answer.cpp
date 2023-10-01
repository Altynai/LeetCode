using int64 = long long;

class Solution {
public:
  int maxKDivisibleComponents(int n, vector<vector<int>> &edges,
                              vector<int> &values, int k) {
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int ans = 0;
    function<int64(int, int)> dfs = [&](int u, int fa) -> int64 {
      int64 res = values[u];
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        res += dfs(v, u);
      }
      if (res % k == 0) {
        res = 0;
        ans++;
      }
      return res;
    };

    dfs(0, -1);
    return ans;
  }
};
