class Solution {
public:
  int countPyramids(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    int ans = 0;
    for (int x = 0; x < 2; x++) {
      vector<vector<int>> dp(n, vector<int>(m, 0));
      for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
          if (a[i][j] == 0)
            continue;
          dp[i][j] = 1;
          if (i + 1 < n && j > 0 && j + 1 < m)
            dp[i][j] =
                1 + min(min(dp[i + 1][j - 1], dp[i + 1][j]), dp[i + 1][j + 1]);
          ans += dp[i][j] - 1;
        }
      }
      reverse(a.begin(), a.end());
    }
    return ans;
  }
};
