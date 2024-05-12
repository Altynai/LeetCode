class Solution {
public:
  bool satisfiesConditions(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i + 1 < n and a[i][j] != a[i + 1][j])
          return 0;
        if (j + 1 < m and a[i][j] == a[i][j + 1])
          return 0;
      }
    }
    return 1;
  }
};
