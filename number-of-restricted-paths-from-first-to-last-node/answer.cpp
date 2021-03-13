struct Dijkstra {
#define T int
#define inf INT_MAX
#define _maxn 20005     // maximum vertex
#define _maxm 40005 * 2 // maximum vertex

  int n; // total vertex
  int m; // total edges
  int dis[_maxn];

  int head[_maxn];
  int nxt[_maxm];
  int to[_maxm];
  int weight[_maxm];

  void init(int _n) {
    n = _n;
    m = 0;
    for (int i = 0; i < n; i++)
      head[i] = -1;
  }

  void edge(int u, int v, T w) {
    to[m] = v;
    weight[m] = w;
    nxt[m] = head[u];
    head[u] = m++;
  }

  void run(int s) {
    for (int i = 0; i < n; i++)
      dis[i] = inf;

    set<pair<int, int>> q;
    dis[s] = 0;
    q.insert({0, s});

    while (!q.empty()) {
      int u = q.begin()->second;
      q.erase(q.begin());
      for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = to[i], w = dis[u] + weight[i];
        if (w < dis[v]) {
          dis[v] = w;
          q.insert({dis[v], v});
        }
      }
    }
  }

  int count(int s) {
    const int MOD = 1000000007;
    vector<int> cnt(n, 0);
    cnt[s] = 1;
    set<pair<int, int>> q;
    q.insert({dis[s], s});

    while (!q.empty()) {
      int u = q.begin()->second;
      q.erase(q.begin());
      for (int i = head[u]; i != -1; i = nxt[i]) {
        int v = to[i];
        if (dis[v] > dis[u]) {
          cnt[v] += cnt[u];
          cnt[v] %= MOD;
          q.insert({dis[v], v});
        }
      }
    }
    return cnt[0];
  }
} dijk;

class Solution {
public:
  int countRestrictedPaths(int n, vector<vector<int>> &edges) {
    dijk.init(n);
    for (auto &e : edges) {
      int u = e[0] - 1;
      int v = e[1] - 1;
      int w = e[2];
      dijk.edge(u, v, w);
      dijk.edge(v, u, w);
    }
    dijk.run(n - 1);
    return dijk.count(n - 1);
  }
};
