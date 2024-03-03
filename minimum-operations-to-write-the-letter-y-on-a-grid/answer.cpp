class Solution {
public:
  int minimumOperationsToWriteY(vector<vector<int>> &a) {
    int n = a.size();

    auto Count = [&](int c0, int c1) -> int {
      // center: n / 2, n / 2
      int res = 0;
      for (int i = 0; i <= n / 2; i++)
        res += int(a[i][i] != c0);
      for (int i = 0; i < n / 2; i++)
        res += int(a[i][n - 1 - i] != c0);
      for (int i = n / 2 + 1; i < n; i++)
        res += int(a[i][n / 2] != c0);

      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i <= n / 2 and i == j)
            continue;
          if (i < n / 2 and j == n - 1 - i)
            continue;
          if (i >= n / 2 + 1 and j == n / 2)
            continue;
          res += int(a[i][j] != c1);
        }
      }
      return res;
    };

    int ans = INT_MAX;
    for (int i = 0; i <= 2; i++) {
      for (int j = 0; j <= 2; j++) {
        if (i == j)
          continue;
        ans = min(ans, Count(i, j));
      }
    }
    return ans;
  }
};
