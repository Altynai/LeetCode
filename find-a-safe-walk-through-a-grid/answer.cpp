template <typename T> struct SPFA {
  const T inf = numeric_limits<T>::max();

  int n; // total vertex
  vector<T> dis;
  vector<bool> inq;
  vector<vector<pair<T, int>>> g; /* weight, to */

  // mcfx optimization: https://ad1024.space/articles/15
  int mcfx_timesamp, klock;

  void reset_mcfx_optimization() {
    const unsigned SEED =
        chrono::steady_clock::now().time_since_epoch().count();
    mt19937 rng(SEED);
    mcfx_timesamp = rng() % 10 + 3;
    klock = 0;
  }

  void init(int _n) {
    n = _n;
    dis.resize(n);
    inq.resize(n);
    g.resize(n);
    g.assign(n, vector<pair<T, int>>());

    reset_mcfx_optimization();
  }

  void edge(int u, int v, T w) {
    g[u].emplace_back(w, v);
    // g[v].emplace_back(w, u);
  }

  void relax(deque<int> &dq, int v, T w) {
    if (w < dis[v]) {
      dis[v] = w;
      if (!inq[v]) {
        inq[v] = 1;

        if (++klock == mcfx_timesamp) {
          reset_mcfx_optimization();
          dq.push_front(v);
        } else
          dq.push_back(v);
      }
    }
  }

  T run(int s, int t) {
    /*
     * 判断 s 点是否能抵达一个负权环，只需记录最短路经过了多少条边，当经过了至少
     *n 条边时，说明 s 点可以抵达一个负权环
     **/
    dis.assign(n, inf);
    inq.assign(n, false);

    deque<int> dq;
    relax(dq, s, 0);

    while (!dq.empty()) {
      int u = dq.front();
      dq.pop_front();
      inq[u] = 0;
      for (auto &[w, v] : g[u])
        relax(dq, v, dis[u] + w);
    }
    return dis[t];
  }
};
SPFA<int> spfa;

class Solution {
public:
  bool findSafeWalk(vector<vector<int>> &a, int health) {
    int n = a.size(), m = a[0].size();
    spfa.init(n * m * 2);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int in = i * m + j, out = i * m + j + n * m;
        spfa.edge(in, out, a[i][j]);
        if (j + 1 < m)
          spfa.edge(out, i * m + j + 1, 0);
        if (j > 0)
          spfa.edge(out, i * m + j - 1, 0);
        if (i + 1 < n)
          spfa.edge(out, (i + 1) * m + j, 0);
        if (i > 0)
          spfa.edge(out, (i - 1) * m + j, 0);
      }
    }
    return health > spfa.run(0, n * m * 2 - 1);
  }
};
