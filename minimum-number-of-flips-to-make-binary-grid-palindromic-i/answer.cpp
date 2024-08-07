class Solution {
public:
  int minFlips(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m / 2; j++) {
        if (a[i][j] != a[i][m - 1 - j])
          ans++;
      }
    }

    int cnt = 0;
    for (int j = 0; j < m; j++) {
      for (int i = 0; i < n / 2; i++) {
        if (a[i][j] != a[n - 1 - i][j])
          cnt++;
      }
    }

    return min(ans, cnt);
  }
};
