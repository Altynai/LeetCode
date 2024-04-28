using int64 = long long;

class Solution {
public:
  long long numberOfRightTriangles(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<int> row(n), col(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++)
        row[i] += a[i][j], col[j] += a[i][j];
    }

    int64 ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 1)
          ans += 1LL * (row[i] - 1) * (col[j] - 1);
      }
    }
    return ans;
  }
};
