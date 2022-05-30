const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool between(int l, int x, int r) { return l <= x && x <= r; }
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int minimumObstacles(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> d(n, vector<int>(m, INT_MAX));

    deque<pair<int, int>> q;
    q.push_back({0, 0});
    d[0][0] = 0;

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop_front();

      for (int k = 0; k < 4; k++) {
        int x2 = x + dx[k];
        int y2 = y + dy[k];
        if (inside(n, m, x2, y2)) {
          int dis = d[x][y] + a[x2][y2];
          if (dis < d[x2][y2]) {
            d[x2][y2] = dis;
            if (a[x2][y2] == 0)
              q.push_front({x2, y2});
            else
              q.push_back({x2, y2});
          }
        }
      }
    }
    return d[n - 1][m - 1];
  }
};
