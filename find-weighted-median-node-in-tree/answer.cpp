using int64 = long long;

struct BinaryLifting {
  int n, m;
  vector<vector<pair<int, int>>> g;
  vector<int> depth;
  vector<int64> distance;
  vector<vector<int>> jump;

  BinaryLifting(int _n, const vector<vector<int>> &_edges) : n(_n) {
    m = (int)log2(n) + 1;
    depth.resize(n);
    distance.resize(n);
    jump.resize(n);
    g.resize(n);
    for (int i = 0; i < n; i++) {
      depth[i] = -1;
      distance[i] = 0;
      jump[i] = vector<int>(m, -1);
      g[i].clear();
    }

    for (auto e : _edges) {
      int u = e[0], v = e[1], w = e[2];
      g[u].push_back({v, w});
      g[v].push_back({u, w});
    }
  }

  void dfs(int u, int fa, int dep, int64 dis) {
    jump[u][0] = fa;
    depth[u] = dep;
    distance[u] = dis;
    for (auto [v, w] : g[u]) {
      if (v == fa)
        continue;
      dfs(v, u, dep + 1, dis + w);
    }
  }

  // =================== Public APIs ===================
  void rootify(int root) {
    dfs(root, -1, 0, 0);

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

  int depth_distance(int u, int v) {
    int node = lca(u, v);
    return depth[u] + depth[v] - depth[node] * 2;
  }

  int64 weight_distance(int u, int v) {
    int node = lca(u, v);
    return distance[u] + distance[v] - distance[node] * 2;
  }

  int lift(int u, int steps) {
    for (int p = 0; p < m; p++) {
      if (steps & (1 << p)) {
        u = jump[u][p];
      }
    }
    return u;
  }
};

class Solution {
public:
  vector<int> findMedian(int n, vector<vector<int>> &edges,
                         vector<vector<int>> &queries) {
    BinaryLifting bin(n, edges);
    bin.rootify(0);

    int q = queries.size();
    vector<int> ans(q, -1);
    for (int i = 0; i < q; i++) {
      int u = queries[i][0], v = queries[i][1];
      int node = bin.lca(u, v);
      // edge case: v is in the subtree of u
      if (node == u) {
        int64 d = bin.weight_distance(u, v);
        int64 half = (d + 1) / 2;
        for (int l = 0, r = bin.depth_distance(u, v); l <= r;) {
          int mid = (l + r) / 2;
          int p = bin.lift(v, mid);
          int64 len = d - bin.weight_distance(p, v);
          if (len >= half)
            ans[i] = p, l = mid + 1;
          else
            r = mid - 1;
        }
      } else {
        int dep1 = bin.depth_distance(u, node),
            dep2 = bin.depth_distance(v, node);
        int64 d1 = bin.weight_distance(u, node),
              d2 = bin.weight_distance(v, node);
        int64 half = (d1 + d2 + 1) / 2;
        for (int l = 0, r = dep1 + dep2; l <= r;) {
          int mid = (l + r) / 2, p = -1;
          int64 len;
          if (mid <= dep1) {
            p = bin.lift(u, mid);
            len = bin.weight_distance(u, p);
          } else {
            p = bin.lift(v, dep1 + dep2 - mid);
            len = d1 + d2 - bin.weight_distance(v, p);
          }
          if (len >= half)
            ans[i] = p, r = mid - 1;
          else
            l = mid + 1;
        }
      }
    }
    return ans;
  }
};
