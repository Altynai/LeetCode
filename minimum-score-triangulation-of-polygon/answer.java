class Solution {
    public int minScoreTriangulation(int[] A) {
        int n = A.length, m = A.length * 2;
        int[] b = new int[m];
        for (int i = 0; i < m; i++)
            b[i] = A[i % n];

        int[][] dp = new int[m][m];
        for (int[] row: dp)
            Arrays.fill(row, 0x3f3f3f3f);

        for (int i = 0; i + 2 < m; i++)
            dp[i][i + 2] = b[i] * b[i + 1] * b[i + 2];

        for (int step = 3; step < n; step++) {
            for (int i = 0; i < n; i++) {
                int j = i + step;
                for (int k = i + 1; k < j; k++) {
                    int wa = (k == i + 1) ? 0 : dp[i][k];
                    int wb = b[i] * b[j] * b[k];
                    int wc = (k == j - 1) ? 0 : dp[k][j];
                    dp[i][j] = Math.min(dp[i][j], wa + wb + wc);
                }
            }
        }
        
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < n; i++)
            ans = Math.min(ans, dp[i][i + n - 1]);
        return ans;
    }
}
