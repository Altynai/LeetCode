// 前向星 + Dijkstra
template <typename T> struct Dijkstra {
  const T inf = numeric_limits<T>::max();

  int n; // total vertex
  vector<T> dis;
  vector<vector<pair<T, int>>> g; /* weight, to */

  void init(int _n) {
    n = _n;
    dis.resize(n);
    g.resize(n);
    for (int i = 0; i < n; i++)
      g[i].clear();
  }

  void edge(int u, int v, T w) { g[u].emplace_back(w, v); }

  void run(int s) {
    dis.assign(n, inf);

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
  }
};

Dijkstra<long long> dijk, rev_dijk;

class Solution {
public:
  long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2,
                          int dest) {
    dijk.init(n);
    rev_dijk.init(n);

    for (auto &e : edges) {
      int u = e[0], v = e[1], w = e[2];
      dijk.edge(u, v, w);
      rev_dijk.edge(v, u, w);
    }

    rev_dijk.run(dest);
    vector<long long> &rev_d = rev_dijk.dis;

    dijk.run(src1);
    vector<long long> d1 = dijk.dis;

    dijk.run(src2);
    vector<long long> d2 = dijk.dis;

    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
      if (d1[i] != LLONG_MAX and d2[i] != LLONG_MAX and rev_d[i] != LLONG_MAX)
        ans = min(ans, d1[i] + d2[i] + rev_d[i]);
    }
    return ans == LLONG_MAX ? -1 : ans;
  }
};
