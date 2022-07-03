const int N = 1002;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

int dp[N][N];

class Solution {
public:
  int countPaths(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        dp[i][j] = -1;

    function<int(int, int)> dfs = [&](int x, int y) -> int {
      if (dp[x][y] != -1)
        return dp[x][y];

      dp[x][y] = 1;
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (inside(n, m, nx, ny) and a[nx][ny] < a[x][y]) {
          dp[x][y] += dfs(nx, ny);
          dp[x][y] %= MOD;
        }
      }
      return dp[x][y];
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ans += dfs(i, j);
        ans %= MOD;
      }
    }
    return ans;
  }
};
