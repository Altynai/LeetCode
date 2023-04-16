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

  T run(int s, int t) {
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
    return dis[t];
  }
};

class Graph {
private:
  Dijkstra<int> dijk;

public:
  Graph(int n, vector<vector<int>> &edges) {
    dijk.init(n);
    for (auto e : edges)
      dijk.edge(e[0], e[1], e[2]);
  }

  void addEdge(vector<int> e) { dijk.edge(e[0], e[1], e[2]); }

  int shortestPath(int x, int y) {
    int res = dijk.run(x, y);
    return (res == INT_MAX ? -1 : res);
  }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
