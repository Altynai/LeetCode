class Solution {

    private boolean predicate(final int[][] dp, int n, int m, int size, int threshold) {
        for (int i = 1; i + size - 1 <= n; i++) {
            int i2 = i + size - 1;
            for (int j = 1; j + size - 1 <= m; j++) {
                int j2 = j + size - 1;
                if (dp[i2][j2] - dp[i2][j - 1] - dp[i - 1][j2] + dp[i - 1][j - 1] <= threshold)
                    return true;
            }
        }
        return false;
    }

    public int maxSideLength(int[][] mat, int threshold) {
        final int n = mat.length;
        final int m = mat[0].length;
        final int[][] dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
        }

        int l = 0, r = Math.min(n, m), ans = 0;
        while (l <= r) {
            int size = (l + r) >> 1;
            if (predicate(dp, n, m, size, threshold)) {
                ans = size;
                l = size + 1;
            } else {
                r = size - 1;
            }
        }
        return ans;
    }
}
