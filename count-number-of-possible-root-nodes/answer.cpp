class Solution {
public:
  int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses,
                int k) {
    int n = edges.size() + 1;

    vector<vector<int>> adj(n);
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    vector<int> pa(n, -1);
    function<void(int, int)> dfs = [&](int u, int fa) {
      pa[u] = fa;
      for (int v : adj[u]) {
        if (v != fa)
          dfs(v, u);
      }
    };
    dfs(0, -1);

    vector<int> add(n, 0);
    for (auto &g : guesses) {
      int u = g[0], v = g[1];
      if (pa[v] == u) {
        add[0] += 1;
        add[v] -= 1;
      } else {
        assert(pa[u] == v);
        add[u] += 1;
      }
    }

    int ans = 0;
    function<void(int, int, int)> dfs2 = [&](int u, int fa, int val) {
      val += add[u];
      if (val >= k)
        ans++;
      for (int v : adj[u]) {
        if (v != fa)
          dfs2(v, u, val);
      }
    };
    dfs2(0, -1, 0);
    return ans;
  }
};
