class Solution {
    public int numRollsToTarget(int d, int f, int target) {
        final int mod = 1000000000 + 7;
        int[][] dp = new int[d + 1][target + 1];
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = 0; j <= Math.min(target, (i - 1) * f); j++) {
                if (dp[i - 1][j] == 0)
                    continue;
                for (int k = 1; k <= f && k + j <= target; k++)
                    dp[i][j + k] = (dp[i][j + k] + dp[i - 1][j]) % mod;
            }
        }
        return dp[d][target];
    }
}
