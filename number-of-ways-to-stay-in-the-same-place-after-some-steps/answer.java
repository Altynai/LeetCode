class Solution {
    private static final int MOD = 1000000007;

    public int numWays(int steps, int arrLen) {
        int n = Math.min(steps + 1, arrLen);
        int[][] dp = new int[steps + 1][n];
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i - 1][j] > 0) {
                    // left
                    if (j > 0)
                        dp[i][j - 1] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
                    // stay
                    dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
                    // right
                    if (j + 1 < n)
                        dp[i][j + 1] = (dp[i][j + 1] + dp[i - 1][j]) % MOD;
                }
            }
        }
        return dp[steps][0];
    }
}
