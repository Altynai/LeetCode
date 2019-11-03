class Solution {
    public int minimumMoves(int[] nums) {
        int n = nums.length;
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = 0; i + 1 < n; i++)
            dp[i][i + 1] = (nums[i] == nums[i + 1]) ? 1 : 2;
        for (int step = 3; step <= n; step++) {
            for (int i = 0, j; (j = i + step - 1) < n; i++) {
                dp[i][j] = j - i + 1;
                if (nums[i] == nums[j])
                    dp[i][j] = Math.min(dp[i][j], dp[i + 1][j - 1]);
                else {
                    for (int k = i; k < j; k++)
                        dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
}
