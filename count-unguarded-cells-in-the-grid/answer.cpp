class Solution {
public:
  int countUnguarded(int n, int m, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    vector<vector<int>> a(n, vector<int>(m, -1));
    for (auto &g : guards)
      a[g[0]][g[1]] = 1;
    for (auto &w : walls)
      a[w[0]][w[1]] = 0;

    auto check_and_update = [&](int &p, int &type) {
      if (p == -1 and type == 1)
        p = -2;
      if (p >= 0)
        type = p;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 1, type = a[i][0]; j < m; j++)
        check_and_update(a[i][j], type);
      for (int j = m - 2, type = a[i][m - 1]; j >= 0; j--)
        check_and_update(a[i][j], type);
    }
    for (int j = 0; j < m; j++) {
      for (int i = 1, type = a[0][j]; i < n; i++)
        check_and_update(a[i][j], type);
      for (int i = n - 2, type = a[n - 1][j]; i >= 0; i--)
        check_and_update(a[i][j], type);
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (a[i][j] == -1)
          ans++;
    return ans;
  }
};
