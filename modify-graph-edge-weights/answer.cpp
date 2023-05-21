template <class T> bool umin(T &a, const T b) { return b < a ? a = b, 1 : 0; }

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

  vector<int> run(int s) {
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
Dijkstra<int> dijk;

class Solution {
public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges,
                                         int src, int dst, int target) {
    int m = edges.size();
    // dijkstra = n * logn = 800
    // enumerate edges = n * (n - 1) / 2 = 5000

    dijk.init(n);
    for (const auto &e : edges) {
      if (e[2] > 0) {
        dijk.edge(e[0], e[1], e[2]);
        dijk.edge(e[1], e[0], e[2]);
      }
    }
    vector<int> dis = dijk.run(src);
    if (dis[dst] < target)
      return {};

    for (auto &e : edges) {
      if (e[2] == -1) {
        dijk.edge(e[0], e[1], 1);
        dijk.edge(e[1], e[0], 1);
        e[2] = 1;

        dis = dijk.run(src);
        if (dis[dst] <= target) {
          e[2] += (target - dis[dst]);

          for (auto &rest : edges) {
            if (rest[2] < 0)
              rest[2] = target;
          }
          break;
        }
      }
    }
    if (dis[dst] > target)
      return {};
    return edges;
  }
};
