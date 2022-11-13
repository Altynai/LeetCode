class Solution {
public:
  int mostProfitablePath(vector<vector<int>> &edges, int bob,
                         vector<int> &amount) {
    int n = amount.size();
    vector<vector<int>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<int> fa(n, -1);
    function<void(int, int)> dfs = [&](int u, int father) {
      fa[u] = father;
      for (int v : adj[u]) {
        if (v == father)
          continue;
        dfs(v, u);
      }
    };
    dfs(0, -1);

    vector<int> path;
    for (int u = bob; u != -1; u = fa[u])
      path.push_back(u);
    int m = path.size();
    for (int i = 0; i < m / 2; i++)
      amount[path[i]] = 0;
    // meeting at the same point
    if (m % 2 == 1)
      amount[path[m / 2]] /= 2;

    int ans = INT_MIN;
    function<void(int, int)> dfs2 = [&](int u, int cur) {
      cur += amount[u];
      // leaf
      if (u != 0 and adj[u].size() == 1)
        ans = max(ans, cur);

      for (int v : adj[u]) {
        if (v == fa[u])
          continue;
        dfs2(v, cur);
      }
    };
    dfs2(0, 0);
    return ans;
  }
};
