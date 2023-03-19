class Solution {
public:
  bool checkValidGrid(vector<vector<int>> &a) {
    int n = a.size();
    int m = n * n;
    vector<pair<int, int>> where(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        where[a[i][j]] = {i, j};
      }
    }

    auto [x, y] = where[0];
    if (x != 0 or y != 0)
      return 0;

    for (int i = 1; i < m; i++) {
      auto [x2, y2] = where[i];
      int dx = abs(x - x2), dy = abs(y - y2);
      if ((dx == 1 and dy == 2) or (dx == 2 and dy == 1))
        x = x2, y = y2;
      else
        return 0;
    }
    return 1;
  }
};
