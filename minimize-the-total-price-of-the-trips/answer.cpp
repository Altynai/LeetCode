struct BinaryLifting {
  int n, m;
  vector<vector<int>> g;
  vector<int> father; // ancestor
  vector<int> depth;
  vector<vector<int>> jump;

  BinaryLifting(int _n) : n(_n) {
    g.resize(n);
    father.resize(n);
    depth.resize(n);
    for (int i = 0; i < n; i++) {
      g[i].clear();
      father[i] = depth[i] = -1;
    }
  }

  void dfs(int u, int fa, int d) {
    father[u] = fa;
    depth[u] = d;
    for (int v : g[u]) {
      if (v == fa)
        continue;
      dfs(v, u, d + 1);
    }
  }

  // =================== Public APIs ===================
  void addEdge(int u, int v) {
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  void initJump(int root) {
    dfs(root, -1, 0);

    int d = *max_element(depth.begin(), depth.end());
    m = 1;
    while ((1 << m) <= d)
      m++;

    jump.resize(n);
    for (int i = 0; i < n; i++) {
      jump[i].resize(m);
      jump[i].assign(m, -1);
      jump[i][0] = father[i];
    }
    assert(jump[root][0] == -1);

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
  int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price,
                        vector<vector<int>> &trips) {
    BinaryLifting bin(n);
    for (auto e : edges)
      bin.addEdge(e[0], e[1]);

    bin.initJump(0);
    vector<int> times(n, 0);
    for (auto trip : trips) {
      int u = trip[0], v = trip[1];
      int r = bin.lca(u, v);
      times[u]++;
      times[v]++;
      times[r]--;
      int fa = bin.father[r];
      if (fa != -1)
        times[fa]--;
    }

    vector<vector<int>> &adj = bin.g;
    vector<vector<int>> dp(n, vector<int>(2, INT_MAX));

    function<void(int, int)> dfs = [&](int u, int fa) {
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        dfs(v, u);
        times[u] += times[v];
      }

      dp[u][0] = price[u] * times[u];
      dp[u][1] = price[u] / 2 * times[u];
      for (int v : adj[u]) {
        if (v == fa)
          continue;
        dp[u][1] += dp[v][0];
        dp[u][0] += min(dp[v][0], dp[v][1]);
      }
    };
    dfs(0, -1);
    return min(dp[0][0], dp[0][1]);
  }
};
