const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool between(int l, int x, int r) { return l <= x && x <= r; }
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int minTimeToReach(vector<vector<int>> &t) {
    int n = t.size(), m = t[0].size();
    // easy to see we should extend nodes in normal Dijkstra
    // dis[i][j][0]: minimal time to enter room[i][j] when next move takes 1 sec
    // dis[i][j][1]: same but when next move takes 2 sec

    vector<vector<vector<int>>> dis(
        n, vector<vector<int>>(m, vector<int>(2, INT_MAX)));

    using State = array<int, 4>; // (dis, x, y, 0/1)
    priority_queue<State, vector<State>, greater<State>> q;
    dis[0][0][0] = 0;
    q.push({0, 0, 0, 0});

    while (!q.empty()) {
      auto [d, x, y, sec] = q.top();
      q.pop();
      // skip invalid node
      if (dis[x][y][sec] != d)
        continue;

      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!inside(n, m, nx, ny))
          continue;

        // int nd = max(t[nx][ny], d) + (sec + 1); // for harder version
        int nd = max(t[nx][ny], d) + 1;
        if (nd < dis[nx][ny][sec ^ 1]) {
          dis[nx][ny][sec ^ 1] = nd;
          q.push({nd, nx, ny, sec ^ 1});
        }
      }
    }
    return min(dis[n - 1][m - 1][0], dis[n - 1][m - 1][1]);
  }
};
