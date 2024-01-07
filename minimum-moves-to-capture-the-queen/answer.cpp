const int N = 8;

inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
    a--, b--, c--, d--, e--, f--;

    auto Get = [&](int sx, int sy, int bx, int by, vector<int> dx,
                   vector<int> dy) -> int {
      vector<vector<int>> dis(N, vector<int>(N, INT_MAX));
      dis[sx][sy] = 0;
      queue<pair<int, int>> que;
      que.push({sx, sy});
      while (!que.empty()) {
        auto [x, y] = que.front();
        que.pop();

        for (int k = 0; k < 4; k++) {
          int x1 = x + dx[k], y1 = y + dy[k];
          while (inside(N, N, x1, y1)) {
            if (x1 == bx and y1 == by)
              break;
            if (dis[x1][y1] > dis[x][y] + 1) {
              dis[x1][y1] = dis[x][y] + 1;
              que.push({x1, y1});
            }
            x1 += dx[k], y1 += dy[k];
          }
        }
      }
      return dis[e][f];
    };

    int ans = INT_MAX;
    // bishop stays, moves rock
    ans = min(ans, Get(a, b, c, d, {0, 0, 1, -1}, {1, -1, 0, 0}));
    // moves away bishop, moves rock
    ans = min(ans, 1 + Get(a, b, -1, -1, {0, 0, 1, -1}, {1, -1, 0, 0}));

    // rock stays, moves bishop
    int m = Get(c, d, a, b, {-1, -1, 1, 1}, {1, -1, -1, 1});
    if (m != INT_MAX)
      ans = min(ans, m);
    // moves away rock, moves bishop
    m = Get(c, d, -1, -1, {-1, -1, 1, 1}, {1, -1, -1, 1});
    if (m != INT_MAX)
      ans = min(ans, 1 + m);
    return ans;
  }
};
