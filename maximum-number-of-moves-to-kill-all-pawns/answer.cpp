#define bit(n, i) (((n) >> (i)) & 1)

const int N = 50;
const int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};

inline bool between(int l, int x, int r) { return l <= x && x <= r; }
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int maxMoves(int kx, int ky, vector<vector<int>> &p) {

    p.insert(p.begin(), {kx, ky});
    int m = p.size();

    // BFS to pre-compute m x m distances
    vector<vector<int>> ids(N, vector<int>(N, -1));
    for (int i = 0; i < m; i++)
      ids[p[i][0]][p[i][1]] = i;

    vector<vector<int>> dis(m, vector<int>(m, INT_MAX));
    for (int i = 0; i < m; i++) {
      vector<vector<bool>> vis(N, vector<bool>(N, 0));
      queue<array<int, 3>> que;
      que.push({p[i][0], p[i][1], 0});
      vis[p[i][0]][p[i][1]] = 1;
      dis[i][i] = 0;

      while (!que.empty()) {
        auto [x0, y0, d] = que.front();
        que.pop();
        for (int k = 0; k < 8; k++) {
          int x1 = x0 + dx[k];
          int y1 = y0 + dy[k];
          if (inside(N, N, x1, y1) and !vis[x1][y1]) {
            vis[x1][y1] = 1;
            int id = ids[x1][y1];
            if (id != -1)
              dis[i][id] = d + 1;
            que.push({x1, y1, d + 1});
          }
        }
      }
    }

    // dp[mask][cur][turn]
    // turn: 0 alice, 1 bob
    vector<vector<int>> dp(1 << m, vector<int>(m, -1));

    function<int(int, int, int)> dfs = [&](int mask, int cur, int turn) -> int {
      if (mask == (1 << m - 1))
        return 0;

      int &res = dp[mask][cur];
      if (res != -1)
        return res;

      for (int nxt = 0; nxt < m; nxt++) {
        if (bit(mask, nxt) == 0) {
          int got = dfs(mask | (1 << nxt), nxt, turn ^ 1);
          if (got == -1)
            got = 0;
          got += dis[cur][nxt];
          if (turn == 0)
            res = max(res, got);
          else {
            if (res == -1 or got < res)
              res = got;
          }
        }
      }
      return res;
    };
    return dfs(1 << 0, 0, 0);
  }
};
