const int MOD = 1e9 + 7;

void add(int &x, int y) {
  x += y;
  if (x >= MOD)
    x -= MOD;
}

class Solution {
public:
  int checkRecord(int n) {
    // dp[i][j]: number of consecutive L in the last is i, and number of A is j
    vector<vector<int>> dp(3, vector<int>(2, 0));
    dp[0][1] = 1; // 'A'
    dp[1][0] = 1; // 'L'
    dp[0][0] = 1; // 'P'

    vector<vector<int>> ndp(3, vector<int>(2, 0));
    for (int i = 2; i <= n; i++) {

      for (int j = 0; j <= 2; j++)
        for (int k = 0; k <= 1; k++)
          ndp[j][k] = 0;

      for (int j = 0; j <= 2; j++) {
        for (int k = 0; k <= 1; k++) {
          if (dp[j][k] == 0)
            continue;
          // 'A'
          if (k == 0)
            add(ndp[0][k + 1], dp[j][k]);
          // 'L'
          if (j <= 1)
            add(ndp[j + 1][k], dp[j][k]);
          // 'P'
          add(ndp[0][k], dp[j][k]);
        }
      }
      swap(dp, ndp);
    }

    int ans = 0;
    for (auto &row : dp)
      for (int x : row)
        add(ans, x);
    return ans;
  }
};
