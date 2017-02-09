#define Point pair<int, int>
#define MP(a, b) make_pair((a), (b))
#define UNSET -1
const int dx[] = { -1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

class Solution {
public:
  vector<vector<int>> steps;
  int n, m;

  void resetSteps() {
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        steps[i][j] = UNSET;
      }
    }
  }

  void init(vector<vector<int>> &grid) {
    n = grid.size();
    m = 0;
    if (n == 0)
      return;
    m = grid[0].size();
    steps = vector<vector<int>>(n, vector<int>(m, UNSET));
  }

  int bfs(vector<vector<int>> &grid, int x, int y) {
    resetSteps();
    queue<Point> q;
    steps[x][y] = 0;
    q.push(MP(x, y));
    while (!q.empty()) {
      Point front = q.front();
      q.pop();
      int px = front.first, py = front.second;
      for (size_t k = 0; k < 4; k++) {
        int nx = px + dx[k], ny = py + dy[k];
        // outside
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (grid[nx][ny] == 2)
          continue;
        if (steps[nx][ny] != UNSET)
          continue;
        steps[nx][ny] = steps[px][py] + 1;
        if (grid[nx][ny] == 0)
          q.push(MP(nx, ny));
      }
    }
    int ans = 0;
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          if (steps[i][j] == UNSET)
            return UNSET;
          else
            ans += steps[i][j];
        }
      }
    }
    return ans;
  }

  int shortestDistance(vector<vector<int>> &grid) {
    init(grid);
    int ans = UNSET;
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        if (grid[i][j] == 0) {
          int distance = bfs(grid, i, j);
          if (distance > 0 && (ans == UNSET || distance < ans))
            ans = distance;
        }
      }
    }
    return ans;
  }
};
