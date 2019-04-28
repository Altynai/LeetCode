class Solution {
    public int maxUncrossedLines(int[] A, int[] B) {
        int n = A.length, m = B.length;
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
                if (A[i - 1] == B[j - 1])
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
        return dp[n][m];
    }
}
