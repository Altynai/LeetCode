
class Solution {
private:
    void transferStatus(int &a, int b) {
        if (a == -1 || b < a)
            a = b;
    }

public:
    int minPathSum(vector<vector<int> > &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int **dp = new int *[n];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[m];
            memset(dp[i], -1, sizeof(int) * m);
        }
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i + 1 < n)
                    transferStatus(dp[i + 1][j], dp[i][j] + grid[i + 1][j]);
                if (j + 1 < m)
                    transferStatus(dp[i][j + 1], dp[i][j] + grid[i][j + 1]);
            }
        }
        return dp[n - 1][m - 1];
    }
};