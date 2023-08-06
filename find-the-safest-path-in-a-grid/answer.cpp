const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool between(int l, int x, int r) { return l <= x && x <= r; }
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>> &g) {
    int n = g.size();
    if (g[0][0] or g[n - 1][n - 1])
      return 0;

    // distance to the cloest thief
    vector<vector<int>> dis(n, vector<int>(n, INT_MAX));
    deque<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j]) {
          dis[i][j] = 0;
          q.push_back({i, j});
        }
      }
    }
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop_front();
      for (int k = 0; k < 4; k++) {
        int x = i + dx[k], y = j + dy[k];
        if (inside(n, n, x, y) and dis[x][y] == INT_MAX) {
          dis[x][y] = dis[i][j] + 1;
          q.push_back({x, y});
        }
      }
    }

    int ans = 0;
    for (int l = 1, r = n + n; l <= r;) {
      int mid = (l + r) / 2;

      vector<vector<bool>> vis(n, vector<bool>(n, 0));
      deque<pair<int, int>> que;
      if (dis[0][0] >= mid) {
        vis[0][0] = 1;
        que.push_back({0, 0});
      }
      while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop_front();
        for (int k = 0; k < 4; k++) {
          int x = i + dx[k], y = j + dy[k];
          if (inside(n, n, x, y) and !vis[x][y] and dis[x][y] >= mid) {
            vis[x][y] = 1;
            que.push_back({x, y});
          }
        }
      }
      if (vis[n - 1][n - 1])
        ans = mid, l = mid + 1;
      else
        r = mid - 1;
    }
    return ans;
  }
};
