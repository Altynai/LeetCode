struct BinaryLifting {
  int n, m;
  vector<vector<int>> g;
  vector<int> depth;
  vector<vector<int>> jump;

  BinaryLifting(int _n, const vector<vector<int>> &_g) : n(_n), g(_g) {
    m = (int)log2(n) + 1;
    depth.resize(n);
    jump.resize(n);
    for (int i = 0; i < n; i++) {
      depth[i] = -1;
      jump[i] = vector<int>(m, -1);
    }
  }

  void dfs(int u, int fa, int d) {
    jump[u][0] = fa;
    depth[u] = d;
    for (int v : g[u]) {
      if (v == fa)
        continue;
      dfs(v, u, d + 1);
    }
  }

  // =================== Public APIs ===================
  void rootify(int root) {
    dfs(root, -1, 0);

    for (int p = 1; p < m; p++) {
      for (int i = 0; i < n; i++) {
        int k = jump[i][p - 1];
        if (k != -1)
          jump[i][p] = jump[k][p - 1];
      }
    }
  }

  int lca(int u, int v) {
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
  }

  int dist(int u, int v) {
    int node = lca(u, v);
    return depth[u] + depth[v] - depth[node] * 2;
  }
};

class Solution {
public:
  vector<int> minimumWeight(vector<vector<int>> &edges,
                            vector<vector<int>> &queries) {
    int n = edges.size() + 1;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>> g(n);
    for (auto e : edges) {
      int u = e[0], v = e[1], w = e[2];
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
      g[u].push_back(v);
      g[v].push_back(u);
    }

    BinaryLifting bin(n, g);
    bin.rootify(0);

    vector<int> dis(n, 0);
    function<void(int, int)> dfs = [&](int u, int fa) {
      for (auto [v, w] : adj[u]) {
        if (v == fa)
          continue;
        dis[v] = dis[u] + w;
        dfs(v, u);
      }
    };
    dfs(0, -1);

    auto distance = [&](int x, int y) -> int {
      int p = bin.lca(x, y);
      return dis[x] + dis[y] - dis[p] * 2;
    };

    vector<int> ans;
    for (auto query : queries) {
      int x = query[0], y = query[1], z = query[2];
      int res = distance(x, y);
      res += distance(y, z);
      res += distance(x, z);
      ans.push_back(res / 2);
    }
    return ans;
  }
};
