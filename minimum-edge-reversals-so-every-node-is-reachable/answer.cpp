struct Edge {
  int u, v, w, sum;

  Edge() {}
  Edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w), sum(-1) {}
};

class Solution {
public:
  vector<int> minEdgeReversals(int n, vector<vector<int>> &edges) {
    vector<vector<Edge>> adj(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(Edge(u, v, 0));
      adj[v].push_back(Edge(v, u, 1));
    }

    function<void(Edge &)> dfs = [&](Edge &e) {
      e.sum = e.w;
      for (Edge &nxt : adj[e.v]) {
        if (nxt.v == e.u)
          continue;
        if (nxt.sum == -1)
          dfs(nxt);
        e.sum += nxt.sum;
      }
    };

    for (int i = 0; i < n; i++) {
      for (auto &e : adj[i]) {
        if (e.sum == -1)
          dfs(e);
      }
    }

    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++) {
      for (auto &e : adj[i])
        ans[i] += e.sum;
    }
    return ans;
  }
};
