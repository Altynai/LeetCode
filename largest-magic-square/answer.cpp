class Solution {
public:
  int largestMagicSquare(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> r(n + 2, vector<int>(m + 2, 0)), c(r), d(r), d2(r);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int val = a[i - 1][j - 1];
        r[i][j] = r[i][j - 1] + val;
        c[i][j] = c[i - 1][j] + val;
        d[i][j] = d[i - 1][j - 1] + val;
        d2[i][j] = d2[i - 1][j + 1] + val;
      }
    }

    for (int len = min(n, m); len >= 2; len--) {
      for (int i = 1; i + len - 1 <= n; i++) {
        for (int j = 1; j + len - 1 <= m; j++) {
          int sum = r[i][j + len - 1] - r[i][j - 1];
          bool same = 1;
          for (int x = i; same && x <= i + len - 1; x++) {
            if (r[x][j + len - 1] - r[x][j - 1] != sum)
              same = 0;
          }
          for (int y = j; same && y <= j + len - 1; y++) {
            if (c[i + len - 1][y] - c[i - 1][y] != sum)
              same = 0;
          }

          if (same && d[i + len - 1][j + len - 1] - d[i - 1][j - 1] != sum)
            same = 0;
          if (same && d2[i + len - 1][j] - d2[i - 1][j + len - 1 + 1] != sum)
            same = 0;

          if (same)
            return len;
        }
      }
    }
    return 1;
  }
};
