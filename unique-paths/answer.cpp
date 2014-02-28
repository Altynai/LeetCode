
class Solution {
public:
    int uniquePaths(int m, int n) {
        int **dp = new int *[m];
        for (int i = 0; i < m; i++) {
            dp[i] = new int[n];
            memset(dp[i], 0, sizeof(int) * n);
        }
        for (int j = 0; j < n; j++)
            dp[0][j] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] += dp[i - 1][j];
                if (j > 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};