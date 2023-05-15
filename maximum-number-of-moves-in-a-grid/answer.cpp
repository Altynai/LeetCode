template <class T> bool umax(T &a, const T b) { return a < b ? a = b, 1 : 0; }

class Solution {
public:
  int maxMoves(vector<vector<int>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 1));

    int ans = 1;
    for (int j = m - 2; j >= 0; j--) {
      for (int i = 0; i < n; i++) {
        if (i and a[i][j] < a[i - 1][j + 1])
          umax(dp[i][j], dp[i - 1][j + 1] + 1);
        if (a[i][j] < a[i][j + 1])
          umax(dp[i][j], dp[i][j + 1] + 1);
        if (i + 1 < n and a[i][j] < a[i + 1][j + 1])
          umax(dp[i][j], dp[i + 1][j + 1] + 1);
        if (j == 0)
          umax(ans, dp[i][j]);
      }
    }
    return ans - 1;
  }
};
