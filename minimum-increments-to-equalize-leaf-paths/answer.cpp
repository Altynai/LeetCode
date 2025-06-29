using int64 = long long;

class Solution {
public:
  int minIncrease(int n, vector<vector<int>> &edges, vector<int> &cost) {
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    int ans = 0;
    function<int64(int, int)> dfs = [&](int u, int fa) -> int64 {
      vector<int64> children;
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        int64 res = dfs(v, u);
        children.push_back(res);
      }
      if (children.size() == 0)
        return cost[u];

      int64 mx = *max_element(children.begin(), children.end());
      for (int64 got : children) {
        if (got != mx)
          ans++;
      }
      return mx + cost[u];
    };
    dfs(0, -1);
    return ans;
  }
};
