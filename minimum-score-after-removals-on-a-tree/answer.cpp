class Solution {
public:
  int minimumScore(vector<int> &a, vector<vector<int>> &edges) {
    int n = a.size();
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<int> val(n, 0);
    function<int(int, int, int)> dfs = [&](int u, int p, int skip) -> int {
      val[u] = a[u];
      for (int v : adj[u])
        if (v != p and v != skip)
          val[u] ^= dfs(v, u, skip);
      return val[u];
    };

    vector<int> root(3, 0);
    int ans = INT_MAX;

    function<void(int, int, int, int)> dfs2 = [&](int u, int p, int skip,
                                                  int idx) {
      for (int v : adj[u])
        if (v != p and v != skip) {
          dfs2(v, u, skip, idx);
          // cut u - v
          root[idx] ^= val[v];
          root[2] = val[v];

          int ma = *max_element(root.begin(), root.end());
          int mi = *min_element(root.begin(), root.end());
          ans = min(ans, ma - mi);

          // rollback
          root[idx] ^= val[v];
        }
    };

    for (auto &e : edges) {
      // cut e[0] - e[1] for sure and iterate the other cutting edge in 2
      // different sub-trees
      root[0] = dfs(e[0], -1, e[1]);
      root[1] = dfs(e[1], -1, e[0]);

      dfs2(e[0], -1, e[1], 0);
      dfs2(e[1], -1, e[0], 1);
    }

    return ans;
  }
};
