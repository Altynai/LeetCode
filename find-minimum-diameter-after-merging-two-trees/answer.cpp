struct Graph {

  struct Edge {
    int u, v, nxt;
    int dis;

    Edge() {}
    Edge(int _u, int _v, int _nxt) : u(_u), v(_v), nxt(_nxt), dis(-1) {}
  };

  int n;
  vector<int> head;
  vector<Edge> edges;

  Graph() : n(0) {}
  Graph(int _n) {
    n = _n;
    head = vector<int>(n, -1);
    edges = vector<Edge>();
  }

  void addEdge(int u, int v) {
    edges.push_back(Edge(u, v, head[u]));
    head[u] = edges.size() - 1;
  }

  int dfs(Edge &e) {
    if (e.dis != -1)
      return e.dis;

    int d = 0;
    for (int p = head[e.v]; p != -1; p = edges[p].nxt) {
      if (edges[p].v == e.u)
        continue;
      int got = dfs(edges[p]);
      d = max(got, d);
    }
    return e.dis = d + 1;
  }

  int getLongest() {
    int res = INT_MAX;
    for (int i = 0; i < n; i++) {
      int d = 0;
      for (int p = head[i]; p != -1; p = edges[p].nxt) {
        int got = dfs(edges[p]);
        d = max(got, d);
      }
      res = min(d, res);
    }
    return res;
  }

  int getDiameter() {
    int res = 0;
    for (int i = 0; i < n; i++) {
      vector<int> d;
      for (int p = head[i]; p != -1; p = edges[p].nxt) {
        int got = dfs(edges[p]);
        d.push_back(got);
      }
      sort(d.begin(), d.end());
      int m = d.size();
      if (m == 1)
        res = max(d[m - 1], res);
      else if (m > 1)
        res = max(d[m - 1] + d[m - 2], res);
    }
    return res;
  }
};

class Solution {
public:
  int minimumDiameterAfterMerge(vector<vector<int>> &edges1,
                                vector<vector<int>> &edges2) {
    Graph g1(edges1.size() + 1), g2(edges2.size() + 1);
    for (auto &e : edges1) {
      g1.addEdge(e[0], e[1]);
      g1.addEdge(e[1], e[0]);
    }
    for (auto &e : edges2) {
      g2.addEdge(e[0], e[1]);
      g2.addEdge(e[1], e[0]);
    }

    int ans = max(g1.getDiameter(), g2.getDiameter());
    return max(ans, g1.getLongest() + g2.getLongest() + 1);
  }
};
