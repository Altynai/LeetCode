class Solution {
public:
    int numWays(int n, int k) {
        if (n <= 0)
            return 0;
        if (n == 1)
            return k;
        int m = k;
        // dp[i][j]表示前i个
        // j=0表示最后两个颜色不同，j=1表示最后两个颜色相同
        vector<vector<int>> dp;
        dp.resize(n);
        for (int i = 0; i < n; ++i)
            dp[i].resize(2);
        dp[1][0] = m * (m - 1);
        dp[1][1] = m;
        for (int i = 1; i + 1 < n; ++i) {
            // 最后两个颜色不同
            dp[i + 1][0] += (m - 1) * dp[i][0];
            dp[i + 1][0] += (m - 1) * dp[i][1];
            // 最后两个颜色相同
            dp[i + 1][1] += dp[i][0];
        }
        return dp[n - 1][0] + dp[n - 1][1];
    }
};