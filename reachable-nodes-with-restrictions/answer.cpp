class Solution {
public:
  int reachableNodes(int n, vector<vector<int>> &edges,
                     vector<int> &restricted) {
    vector<bool> banned(n, 0);
    for (int x : restricted)
      banned[x] = 1;

    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    function<int(int, int)> dfs = [&](int u, int fa) -> int {
      if (banned[u])
        return 0;
      int cnt = 1;
      for (int v : adj[u]) {
        if (v != fa)
          cnt += dfs(v, u);
      }
      return cnt;
    };
    return dfs(0, -1);
  }
};
