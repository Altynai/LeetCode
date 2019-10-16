import java.util.Arrays;

class Solution {
    private static final int MOD = 1000000007;

    private int add(int a, int b) {
        return (a + b) % MOD;
    }

    public int dieSimulator(int n, int[] rollMax) {
        int m = Arrays.stream(rollMax).max().getAsInt();
        int[][][] dp = new int[n][6][m + 1];
        for (int i = 0; i < 6; i++)
            dp[0][i][1] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 6; j++) {
                // same
                for (int k = 1; k <= rollMax[j]; k++) {
                    dp[i][j][k] = add(dp[i][j][k], dp[i - 1][j][k - 1]);
                }
                // not same
                for (int k = 0; k < 6; k++) {
                    if (j == k)
                        continue;
                    for (int t = 1; t <= rollMax[k]; t++)
                        dp[i][j][1] = add(dp[i][j][1], dp[i - 1][k][t]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 1; j <= rollMax[i]; j++)
                ans = add(ans, dp[n - 1][i][j]);
        }
        return ans;
    }
}
