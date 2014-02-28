
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0)
            return 0;
        int n = obstacleGrid[0].size();

        int **dp = new int *[m];
        for (int i = 0; i < m; i++) {
            dp[i] = new int[n];
            memset(dp[i], 0, sizeof(int) * n);
        }
        dp[0][0] = 1 - obstacleGrid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0)
                    continue;
                if (j + 1 < n && obstacleGrid[i][j + 1] == 0)
                    dp[i][j + 1] += dp[i][j];
                if (i + 1 < m && obstacleGrid[i + 1][j] == 0)
                    dp[i + 1][j] += dp[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};