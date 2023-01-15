using int64 = long long;

struct Edge {
  int u, v;
  int64 w;
};

class Solution {
public:
  int64 maxOutput(int n, vector<vector<int>> &edges, vector<int> &price) {
    vector<vector<Edge>> adj(n);
    for (auto e : edges) {
      adj[e[0]].push_back({e[0], e[1], -1});
      adj[e[1]].push_back({e[1], e[0], -1});
    }

    function<int64(Edge &)> Dfs = [&](Edge &e) -> int64 {
      if (e.w != -1)
        return e.w;

      int64 best = 0;
      for (Edge &nxt : adj[e.v]) {
        if (nxt.v == e.u)
          continue;
        best = max(best, Dfs(nxt));
      }
      return e.w = best + price[e.v];
    };

    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      for (Edge &e : adj[i])
        ans = max(ans, Dfs(e));
    }
    return ans;
  }
};
