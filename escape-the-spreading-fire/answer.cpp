// https://cp-algorithms.com/graph/01_bfs.html
struct BFS {
  int n;                            // total vertex
  vector<vector<pair<int, int>>> g; /* weight = {0, 1}, to */

  void init(int _n) {
    n = _n;
    g.resize(n);
    for (int i = 0; i < n; i++)
      g[i].clear();
  }

  void edge(int u, int v, int w) {
    assert(w == 0 or w == 1);
    g[u].emplace_back(w, v);
    g[v].emplace_back(w, u);
  }

  vector<int> run(const vector<int> &nodes) {
    vector<int> d(n, INT_MAX);
    deque<int> q;

    for (int s : nodes) {
      d[s] = 0;
      q.push_front(s);
    }

    while (!q.empty()) {
      int u = q.front();
      q.pop_front();
      for (auto [w, v] : g[u]) {
        if (d[u] + w < d[v]) {
          d[v] = d[u] + w;
          if (w == 1)
            q.push_back(v);
          else
            q.push_front(v);
        }
      }
    }
    return d;
  }

  vector<int> run(int s) { return run(vector<int>(1, s)); }

} bfs01;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int maximumMinutes(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    int total_n = n * m;

    bfs01.init(total_n);
    vector<int> fires;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1)
          fires.push_back(i * m + j);
        if (a[i][j] != 2) {
          for (int k = 0; k < 4; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (inside(n, m, nx, ny) and a[nx][ny] != 2) {
              bfs01.edge(i * m + j, nx * m + ny, 1);
            }
          }
        }
      }
    }
    vector<int> dis = bfs01.run(fires);

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    auto bfs = [&](int wait) -> bool {
      if (wait >= dis[0])
        return 0;

      for (int i = 0; i < n; i++)
        vis[i].assign(m, 0);

      deque<array<int, 3>> q;
      q.push_back({0, 0, wait});
      vis[0][0] = 1;

      while (!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop_front();

        for (int k = 0; k < 4; k++) {
          int nx = x + dx[k], ny = y + dy[k];
          if (!inside(n, m, nx, ny) or a[nx][ny] != 0 or vis[nx][ny])
            continue;

          int nid = nx * m + ny;
          if (nx == n - 1 and ny == m - 1) {
            if (t + 1 > dis[nid])
              continue;
          } else if (t + 1 >= dis[nid])
            continue;

          vis[nx][ny] = 1;
          q.push_back({nx, ny, t + 1});
        }
      }
      return vis[n - 1][m - 1];
    };

    int ans = -1;
    for (int l = 0, r = 1e9; l <= r;) {
      int mid = (l + r) >> 1;
      if (bfs(mid))
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};
