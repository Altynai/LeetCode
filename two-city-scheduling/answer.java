class Solution {
    public int twoCitySchedCost(int[][] costs) {
        int n = costs.length;
        int[][] dp = new int[n + 1][n + 1];
        for(int[] sub : dp) 
            Arrays.fill(sub, Integer.MAX_VALUE);

        dp[1][1] = costs[0][0];
        dp[1][0] = costs[0][1];
        for (int i = 2; i <= n; i++) {
            int a = costs[i - 1][0], b = costs[i - 1][1];
            for (int j = 0; j <= i; j++) {
                if (j > 0) 
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j - 1] + a);
                if (j < i)
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + b);
            }
        }
        return dp[n][n >> 1];
    }
}
