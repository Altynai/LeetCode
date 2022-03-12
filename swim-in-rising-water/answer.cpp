const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
inline bool inside(int n, int m, int r, int c) {
  return r >= 0 && r < n && c >= 0 && c < m;
}

class Solution {
public:
  int swimInWater(vector<vector<int>> &a) {
    int n = a.size(), ans = -1;

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    function<void(int, int, int)> dfs = [&](int x, int y, int t) {
      vis[x][y] = 1;
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (inside(n, n, nx, ny) and !vis[nx][ny] and a[nx][ny] <= t)
          dfs(nx, ny, t);
      }
    };
    for (int l = a[0][0], r = n * n - 1; l <= r;) {
      for (int i = 0; i < n; i++)
        vis[i].assign(n, false);
      int mid = (l + r) / 2;
      dfs(0, 0, mid);
      if (vis[n - 1][n - 1])
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};
