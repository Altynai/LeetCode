class Solution {
public:
  int countIslands(vector<vector<int>> &a, int k) {
    int n = a.size(), m = a[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));

    function<void(int, int, int &)> dfs = [&](int x, int y, int &mod) {
      vis[x][y] = 1;
      assert(a[x][y] > 0);
      mod = (mod + a[x][y]) % k;
      if (y + 1 < m and !vis[x][y + 1] and a[x][y + 1] > 0)
        dfs(x, y + 1, mod);
      if (y > 0 and !vis[x][y - 1] and a[x][y - 1] > 0)
        dfs(x, y - 1, mod);
      if (x + 1 < n and !vis[x + 1][y] and a[x + 1][y] > 0)
        dfs(x + 1, y, mod);
      if (x > 0 and !vis[x - 1][y] and a[x - 1][y] > 0)
        dfs(x - 1, y, mod);
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!vis[i][j] and a[i][j] > 0) {
          int mod = 0;
          dfs(i, j, mod);
          if (mod == 0)
            ans++;
        }
      }
    }
    return ans;
  }
};
