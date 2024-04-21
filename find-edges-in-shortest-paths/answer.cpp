using int64 = long long;

template <typename T> struct Dijkstra {
  const T inf = numeric_limits<T>::max();

  int n;                          // total vertex
  vector<vector<pair<T, int>>> g; /* weight, to */

  void init(int _n) {
    n = _n;
    g.resize(n);
    for (int i = 0; i < n; i++)
      g[i].clear();
  }

  void edge(int u, int v, T w) { g[u].emplace_back(w, v); }

  vector<T> run(int s) {
    vector<T> dis(n, inf);

    using State = pair<T, int>;
    priority_queue<State, vector<State>, greater<State>> q;
    dis[s] = 0;
    q.push({0, s});

    while (!q.empty()) {
      auto [d, u] = q.top();
      q.pop();
      // skip invalid node
      if (dis[u] != d)
        continue;

      for (auto [weight, v] : g[u]) {
        T w = dis[u] + weight;
        if (w < dis[v]) {
          dis[v] = w;
          q.push({dis[v], v});
        }
      }
    }
    return dis;
  }
};

class Solution {
public:
  vector<bool> findAnswer(int n, vector<vector<int>> &edges) {
    Dijkstra<int64> dijk;
    dijk.init(n);
    for (auto &e : edges) {
      dijk.edge(e[0], e[1], e[2]);
      dijk.edge(e[1], e[0], e[2]);
    }

    int m = edges.size();
    vector<bool> ans(m, 0);
    vector<int64> d0 = dijk.run(0);
    if (d0[n - 1] == dijk.inf)
      return ans;

    vector<int64> d1 = dijk.run(n - 1);
    for (int i = 0; i < m; i++) {
      int u = edges[i][0], v = edges[i][1], w = edges[i][2];
      if (d0[u] <= d0[v])
        ans[i] = (d0[u] + w + d1[v] == d0[n - 1]);
      else
        ans[i] = (d0[v] + w + d1[u] == d0[n - 1]);
    }
    return ans;
  }
};
