template <typename T> struct Dijkstra {
  const T inf = numeric_limits<T>::max();

  int n;                          // total vertex
  vector<vector<pair<T, int>>> g; /* weight, to */

  vector<int> disapper;

  void init(int _n, vector<int> &_disapper) {
    disapper = _disapper;
    n = _n;
    g.resize(n);
    for (int i = 0; i < n; i++)
      g[i].clear();
  }

  void edge(int u, int v, T w) {
    g[u].emplace_back(w, v);
    g[v].emplace_back(w, u);
  }

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
        if (w >= disapper[v])
          continue;

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
  vector<int> minimumTime(int n, vector<vector<int>> &edges,
                          vector<int> &disappear) {
    dijk.init(n, disappear);
    for (auto &e : edges)
      dijk.edge(e[0], e[1], e[2]);

    vector<int> ans = dijk.run(0);
    for (auto &x : ans) {
      if (x == dijk.inf)
        x = -1;
    }
    return ans;
  }
};
