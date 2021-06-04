class Solution {
public:
  vector<int> getBiggestThree(vector<vector<int>> &a) {
    set<int> ans;
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        ans.insert(a[i][j]);
    }

    int d[n][m][n + 1];
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        d[i][j][1] = a[i][j];
        int x = j, y = j, r = i, k = 1;
        while (r + 1 < n && x - 1 >= 0 && y + 1 < m) {
          x--, y++, r++, k++;
          d[i][j][k] = d[i][j][k - 1] + a[r][x] + a[r][y];
        }
      }
    }

    int u[n][m][n + 1];
    memset(u, 0, sizeof(u));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < m; j++) {
        u[i][j][1] = a[i][j];
        int x = j, y = j, r = i, k = 1;
        while (r - 1 >= 0 && x - 1 >= 0 && y + 1 < m) {
          x--, y++, r--, k++;
          u[i][j][k] = u[i][j][k - 1] + a[r][x] + a[r][y];
        }
      }
    }

    for (int k = 2; k + k - 1 <= n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          int down = i + k - 1 + k - 1;
          int left = j - k + 1;
          int right = j + k - 1;
          if (down >= n || left < 0 || right >= m)
            continue;

          int tot = d[i][j][k] + u[down][j][k] - a[i + k - 1][left] -
                    a[i + k - 1][right];
          ans.insert(tot);
        }
      }
    }
    vector<int> p(ans.rbegin(), ans.rend());
    return vector<int>(p.begin(), p.begin() + min(3, (int)p.size()));
  }
};
