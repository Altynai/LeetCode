class Solution {
public:
  vector<vector<int>> findFarmland(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 0)
          continue;
        int x = i;
        while (x < n && a[x][j] == 1)
          x++;
        x--;
        int y = j;
        while (y < m && a[x][y] == 1)
          y++;
        y--;
        ans.push_back({i, j, x, y});

        for (int p = i; p <= x; p++)
          for (int q = j; q <= y; q++)
            a[p][q] = 0;
      }
    }
    return ans;
  }
};
