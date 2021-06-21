const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class Solution {
public:
  int countSubIslands(vector<vector<int>> &a, vector<vector<int>> &b) {
    int n = a.size(), m = a[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int sum1 = 0, sum2 = 0;

    function<void(int, int)> dfs = [&](int x, int y) {
      vis[x][y] = 1;
      sum1 += a[x][y];
      sum2 += b[x][y];

      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
          continue;
        if (vis[nx][ny] || b[nx][ny] == 0)
          continue;
        dfs(nx, ny);
      }
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] && b[i][j] == 1) {
          sum1 = sum2 = 0;
          dfs(i, j);
          if (sum1 == sum2)
            ans++;
        }
      }
    }
    return ans;
  }
};
