const int C = 26;

int cnt[10005][C];

class Solution {
public:
  vector<int> minOperationsQueries(int n, vector<vector<int>> &edges,
                                   vector<vector<int>> &queries) {
    int m = (int)log2(n) + 1;

    vector<vector<pair<int, int>>> g(n); // vertex, edge weight
    vector<int> depth(n);
    vector<vector<int>> jump(n, vector<int>(m, -1));

    for (auto &e : edges) {
      g[e[0]].push_back({e[1], e[2] - 1});
      g[e[1]].push_back({e[0], e[2] - 1});
    }

    function<void(int, int, int)> dfs = [&](int u, int fa, int d) {
      jump[u][0] = fa;
      depth[u] = d;
      for (auto &[v, w] : g[u]) {
        if (v != fa) {
          copy(cnt[u], cnt[u] + C, cnt[v]);
          cnt[v][w]++;
          dfs(v, u, d + 1);
        }
      }
    };
    dfs(0, -1, 0);

    for (int p = 1; p < m; p++) {
      for (int i = 0; i < n; i++) {
        int k = jump[i][p - 1];
        if (k != -1)
          jump[i][p] = jump[k][p - 1];
      }
    }

    auto lca = [&](int u, int v) -> int {
      if (depth[u] < depth[v])
        swap(u, v);

      int dist = depth[u] - depth[v];
      for (int p = 0; p < m; p++) {
        if (dist & (1 << p)) {
          u = jump[u][p];
        }
      }
      if (u == v)
        return u;

      for (int p = m - 1; p >= 0; p--) {
        if (jump[u][p] != jump[v][p])
          u = jump[u][p], v = jump[v][p];
      }
      return jump[u][0];
    };

    int q = queries.size();
    vector<int> ans(q, 0);
    for (int i = 0; i < q; i++) {
      int u = queries[i][0], v = queries[i][1];
      int p = lca(u, v);
      int distance = depth[u] + depth[v] - depth[p] * 2;
      ;

      int val = 0;
      for (int j = 0; j < C; j++) {
        val = max(val, cnt[u][j] + cnt[v][j] - 2 * cnt[p][j]);
      }
      ans[i] = distance - val;
    }
    return ans;
  }
};
