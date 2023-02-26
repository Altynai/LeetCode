const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool between(int l, int x, int r) { return l <= x && x <= r; }
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int minimumTime(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();

    using State = array<int, 3>;
    priority_queue<State, vector<State>, greater<State>> q;
    vector<vector<int>> tm(n, vector<int>(m, -1));

    auto HasGoodNeighbour = [&](int x, int y) -> bool {
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!inside(n, m, nx, ny))
          continue;
        if (tm[nx][ny] != -1)
          return 1;
      }
      return 0;
    };

    q.push({0, 0, 0});
    tm[0][0] = 0;

    while (!q.empty()) {
      auto [t, x, y] = q.top();
      q.pop();

      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (!inside(n, m, nx, ny))
          continue;

        int nt = -1;
        if (t + 1 >= a[nx][ny])
          nt = t + 1;
        else if (HasGoodNeighbour(x, y)) {
          // waiting: move to a neighbour and jump back
          if (t % 2 == a[nx][ny] % 2)
            nt = a[nx][ny] + 1;
          else
            nt = a[nx][ny];
        }
        if (nt == -1)
          continue;

        if (tm[nx][ny] == -1 or nt < tm[nx][ny]) {
          tm[nx][ny] = nt;
          q.push({nt, nx, ny});
        }
      }
    }

    return tm[n - 1][m - 1];
  }
};
