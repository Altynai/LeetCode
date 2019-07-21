import java.util.Arrays;

class Solution {
    private int max(int[] a, int i, int j) {
        int ans = a[i];
        for (int k = i + 1; k <= j; k++)
            ans = Math.max(ans, a[k]);
        return ans;
    }

    public int mctFromLeafValues(int[] arr) {
        int n = arr.length;
        int[][] dp = new int[n][n];
        for (int[] row : dp)
            Arrays.fill(row, -1);
        for (int i = 0; i < n; i++)
            dp[i][i] = 0;
        for (int i = 0; i < n - 1; i++)
            dp[i][i + 1] = arr[i] * arr[i + 1];

        for (int step = 3; step <= n; step++) {
            for (int i = 0; i + step <= n; i++) {
                int j = i + step - 1;
                for (int k = i; k < j; k++) {
                    int m = dp[i][k] + dp[k + 1][j] + max(arr, i, k) * max(arr, k + 1, j);
                    if (dp[i][j] == -1 || m < dp[i][j])
                        dp[i][j] = m;
                }
            }
        }
        return dp[0][n - 1];
    }
}
