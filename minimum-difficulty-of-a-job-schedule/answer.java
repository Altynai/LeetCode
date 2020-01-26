import java.util.Arrays;

class Solution {
  public int minDifficulty(int[] jobDifficulty, int d) {
    final int n = jobDifficulty.length;

    final int[][] max = new int[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
      max[i][i] = jobDifficulty[i - 1];
      for (int j = i + 1; j <= n; j++) max[i][j] = Math.max(max[i][j - 1], jobDifficulty[j - 1]);
    }

    final int[][] dp = new int[n + 1][d + 1];
    for (int[] r : dp) Arrays.fill(r, -1);
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < d; j++) {
        if (dp[i][j] == -1) continue;
        for (int k = i + 1; k <= n; k++) {
          int v = dp[i][j] + max[i + 1][k];
          if (dp[k][j + 1] == -1 || v < dp[k][j + 1]) dp[k][j + 1] = v;
        }
      }
    }
    return dp[n][d];
  }
}

