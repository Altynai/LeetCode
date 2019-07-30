import java.util.Arrays;

class Solution {
    private int n;
    private int[][] dp;
    private int[] sum;

    private int dfs(int i, int m) {
        if (i > n)
            return 0;
        if (dp[i][m] != -1)
            return dp[i][m];
        // get all
        if (n - i + 1 <= 2 * m)
            return dp[i][m] = sum[n] - sum[i - 1];
        // get x
        for (int j = 1; j <= 2 * m; j++) {
            int get = sum[n] - sum[i - 1] - dfs(i + j, Math.max(m, j));
            if (dp[i][m] == -1 || get > dp[i][m])
                dp[i][m] = get;
        }
        return dp[i][m];
    }

    public int stoneGameII(int[] piles) {
        n = piles.length;
        sum = new int[n + 1];
        dp = new int[n + 1][200];
        for (int[] row : dp)
            Arrays.fill(row, -1);
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + piles[i - 1];
        return dfs(1, 1);
    }
}
