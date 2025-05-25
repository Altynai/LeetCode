template <typename T> struct Dijkstra {
  const T inf = numeric_limits<T>::max();

  int n;                          // total vertex
  vector<vector<pair<T, int>>> g; /* weight, to */

  void init(int _n) {
    n = _n;
    g.resize(n);
    for (int i = 0; i < n; i++)
      g[i].clear();
  }

  void edge(int u, int v, T w) { g[u].emplace_back(w, v); }

  T run(int s) {
    vector<T> dis(n, inf);

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

      if (u == n - 1)
        return d;

      for (auto [weight, v] : g[u]) {
        T w = dis[u] + weight;
        if (w < dis[v]) {
          dis[v] = w;
          q.push({dis[v], v});
        }
      }
    }
    return -1;
  }
};
Dijkstra<int> dijk;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int minMoves(vector<string> &a) {
    int n = a.size(), m = a[0].size();
    dijk.init(n * m);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == '#')
          continue;
        int u = i * m + j;

        for (int k = 0; k < 4; k++) {
          int i2 = i + dx[k], j2 = j + dy[k];
          if (!inside(n, m, i2, j2))
            continue;
          if (a[i2][j2] == '#')
            continue;

          // processed later
          if (isupper(a[i][j]) and a[i][j] == a[i2][j2])
            continue;

          int v = i2 * m + j2;
          // cout << u << " " << v << endl;
          dijk.edge(u, v, 1);
        }
      }
    }

    vector<vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (isupper(a[i][j])) {
          int u = i * m + j;
          pos[a[i][j] - 'A'].push_back(u);
        }
      }
    }
    for (int i = 0; i < 26; i++) {
      int k = pos[i].size();
      for (int j = 1; j < k; j++) {
        dijk.edge(pos[i][j - 1], pos[i][j], 0);
        dijk.edge(pos[i][j], pos[i][j - 1], 0);
      }
    }
    return dijk.run(0);
  }
};
