using int64 = long long;

// T: fee type
template <typename T> struct MinCostFlow {
  static const int MAXN = 205;   // nodes
  static const int MAXM = 11005; // edges
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
MinCostFlow<int64> mcf;

class Solution {
public:
  int64 minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
    int n = robot.size(), m = factory.size();
    int src = 0, dst = n + m + 1;

    mcf.init(dst + 1);
    for (int i = 1; i <= n; i++) {
      mcf.addEdge(src, i, 1, 0);
      for (int j = 1; j <= m; j++) {
        mcf.addEdge(i, n + j, 1, llabs(robot[i - 1] - factory[j - 1][0]));
      }
    }
    for (int j = 1; j <= m; j++)
      mcf.addEdge(n + j, dst, factory[j - 1][1], 0);

    auto [flow, cost] = mcf.minCost(src, dst);
    return cost;
  }
};
