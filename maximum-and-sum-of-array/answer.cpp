struct MinCostFlow {
  static const int MAXN = 105;   // nodes
  static const int MAXM = 11005; // edges
  static const int INF = 0x3f3f3f3f;

  struct edge {
    int u, v, c, f, nxt;
  } e[MAXM << 1];
  int ne, nv, head[MAXN];

  int p[MAXN], dis[MAXN];
  int flow, cost;
  bool vis[MAXN];
  queue<int> q;

  void init(int n) {
    memset(head, -1, sizeof(head));
    ne = 0;
    nv = n;
  }

  void add(int u, int v, int c, int f) {
    e[ne].u = u;
    e[ne].v = v;
    e[ne].c = c;
    e[ne].f = f;
    e[ne].nxt = head[u];
    head[u] = ne++;
  }

  // u->v capacity = c,fee = f
  void addEdge(int u, int v, int c, int f) {
    add(u, v, c, f);
    add(v, u, 0, -f);
  }

  bool spfa(int s, int t) {
    memset(p, -1, sizeof(p));
    memset(vis, 0, sizeof(vis));
    memset(dis, 63, sizeof(dis));
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

  pair<int, int> minCost(int s, int t) {
    cost = flow = 0;
    while (spfa(s, t)) {
      int mflow = INF;
      cost += dis[t];
      for (int i = p[t]; i != -1; i = p[e[i].u])
        if (e[i].c < mflow)
          mflow = e[i].c;
      flow += mflow;
      for (int i = p[t]; i != -1; i = p[e[i].u]) {
        e[i].c -= mflow;
        e[i ^ 1].c += mflow;
      }
    }
    return {flow, cost};
  }
} g;

class Solution {
public:
  int maximumANDSum(vector<int> &a, int m) {
    int n = a.size();
    int s = 0, t = n + m + 1;
    g.init(t + 1);

    for (int i = 1; i <= n; i++) {
      g.addEdge(s, i, 1, 0);
      for (int j = 1; j <= m; j++)
        g.addEdge(i, n + j, 1, -(a[i - 1] & j));
    }
    for (int j = 1; j <= m; j++)
      g.addEdge(n + j, t, 2, 0);

    auto res = g.minCost(s, t);
    return -res.second;
  }
};
