import java.util.Arrays;

class Solution {
    public int palindromePartition(String s, int m) {
        int n = s.length();
        int[][] cost = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
            cost[i][i] = 0;
        for (int step = 2; step <= n; step++) {
            for (int i = 1, j; (j = i + step - 1) <= n; i++) {
                cost[i][j] = cost[i + 1][j - 1] + (s.charAt(i - 1) == s.charAt(j - 1) ? 0 : 1);
            }
        }

        int[][] dp = new int[n + 1][m + 1];
        for (int[] r : dp) {
            Arrays.fill(r, -1);
        }
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < m; k++) {
                if (dp[i][k] == -1)
                    continue;
                for (int j = i + 1; j <= n; j++) {
                    int w = dp[i][k] + cost[i + 1][j];
                    if (dp[j][k + 1] == -1 || w < dp[j][k + 1])
                        dp[j][k + 1] = w;
                }
            }
        }
        return dp[n][m];
    }
}
