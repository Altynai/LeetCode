// functions
template <class T> inline bool umin(T &a, const T b) {
  return b < a ? a = b, 1 : 0;
}
template <class T> inline bool umax(T &a, const T b) {
  return a < b ? a = b, 1 : 0;
}

class Solution {
public:
  int minCost(int m, vector<vector<int>> &edges, vector<int> &f) {
    int n = f.size();
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    vector<int> time(n, INT_MAX);

    for (auto e : edges) {
      int u = e[0], v = e[1], w = e[2];
      if (w > m)
        continue;
      g[u].emplace_back(w, v);
      g[v].emplace_back(w, u);
    }
    for (int i = 0; i < n; i++)
      sort(g[i].begin(), g[i].end());

    using State = array<int, 3>;
    set<State> s;
    s.insert({f[0], 0, 0}); // minCost, pos, time
    time[0] = 0;

    while (s.size()) {
      auto [cost, u, t] = *s.begin();
      s.erase(s.begin());

      if (u == n - 1)
        return cost;

      for (auto [w, v] : g[u]) {
        if (t + w > m)
          continue;

        if (umin(time[v], t + w)) {
          if (time[v] <= m)
            s.insert({cost + f[v], v, t + w});
        }
      }
    }
    return -1;
  }
};
