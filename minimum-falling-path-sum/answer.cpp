class Solution {
private:
    void compare(int& a, int b) {
        if (a == -1 || b < a)
            a = b;
    }

public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n = A.size();
        int dp[n][n];
        memset(dp, -1, sizeof(dp));
        
        for (int i = 0; i < n; i++)
            dp[0][i] = A[0][i];
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = -1; k <= 1; k++) {
                    int p = j + k;
                    if (p < 0 || p >= n)
                        continue;
                    compare(dp[i][j], dp[i - 1][p] + A[i][j]);
                }
            }
        }
        
        int ans = -1;
        for (int j = 0; j < n; j++)
            compare(ans, dp[n - 1][j]);
        return ans;
    }
};
