// T: fee type
template <typename T> struct MinCostFlow {
  static const int MAXN = 125;         // nodes
  static const int MAXM = MAXN * MAXN; // edges
  static const T INF = numeric_limits<T>::max();

  // graph
  struct edge {
    int u, v, nxt;
    int c; // capacity
    T f;   // fee
  } e[MAXM << 1];
  int ne, nv, head[MAXN];

  // spfa
  int p[MAXN];
  T dis[MAXN];
  bool vis[MAXN];
  queue<int> q;

  void init(int n) {
    memset(head, -1, sizeof(head));
    ne = 0;
    nv = n;
  }

  void add(int u, int v, int c, T f) {
    e[ne].u = u;
    e[ne].v = v;
    e[ne].c = c;
    e[ne].f = f;
    e[ne].nxt = head[u];
    head[u] = ne++;
  }

  // u->v capacity = c,fee = f
  void addEdge(int u, int v, int c, T f) {
    add(u, v, c, f);
    add(v, u, 0, -f);
  }

  bool spfa(int s, int t) {
    for (int i = 0; i < nv; i++)
      p[i] = -1, vis[i] = 0, dis[i] = INF;

    int u, v;
    vis[s] = 1;
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
      u = q.front();
      q.pop();
      vis[u] = 0;
      for (int i = head[u]; i != -1; i = e[i].nxt) {
        if (e[i].c > 0) {
          v = e[i].v;
          if (dis[v] > dis[u] + e[i].f) {
            dis[v] = dis[u] + e[i].f;
            p[v] = i;
            if (!vis[v]) {
              q.push(v);
              vis[v] = 1;
            }
          }
        }
      }
    }
    return dis[t] != INF;
  }

  pair<int, T> minCost(int s, int t) {
    T cost = 0;
    int flow = 0;
    while (spfa(s, t)) {
      int mflow = INT_MAX;
      cost += dis[t];
      for (int i = p[t]; i != -1; i = p[e[i].u])
        if (e[i].c < mflow)
          mflow = e[i].c;

      assert(mflow != INT_MAX);
      flow += mflow;
      for (int i = p[t]; i != -1; i = p[e[i].u]) {
        e[i].c -= mflow;
        e[i ^ 1].c += mflow;
      }
    }
    return {flow, cost};
  }
};
MinCostFlow<int> mcf;

const int N = 101;

class Solution {
public:
  int maxScore(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int src = n + N, dst = n + N + 1;

    mcf.init(n + N + 2);
    for (int i = 0; i < n; i++)
      mcf.addEdge(src, i, 1, 0);
    for (int i = 0; i < N; i++)
      mcf.addEdge(n + i, dst, 1, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        mcf.addEdge(i, n + grid[i][j], 1, -grid[i][j]);
      }
    }
    auto [flow, cost] = mcf.minCost(src, dst);
    return -cost;
  }
};
