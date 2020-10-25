const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &h) {
    int n = h.size(), m = h[0].size();
    bool vis[n][m];

    function<void(int, int, int)> dfs = [&](int x, int y, int val) {
      vis[x][y] = 1;
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] ||
            abs(h[x][y] - h[nx][ny]) > val)
          continue;
        dfs(nx, ny, val);
      }
    };

    int l = 0, r = 1e6, ans = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      memset(vis, 0, sizeof(vis));
      dfs(0, 0, mid);
      if (vis[n - 1][m - 1]) {
        ans = mid;
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    assert(ans != -1);
    return ans;
  }
};
