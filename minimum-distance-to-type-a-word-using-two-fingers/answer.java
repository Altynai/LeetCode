import java.util.Arrays;

class Solution {
  private static final int N = 27;

  private int r(int a) {
    return a / 6;
  }

  private int c(int a) {
    return a % 6;
  }

  private int distance(int a, int b) {
    return Math.abs(r(a) - r(b)) + Math.abs(c(a) - c(b));
  }

  public int minimumDistance(String word) {
    final int n = word.length();
    final int[][][] dp = new int[n][N][N];
    for (int[][] d1 : dp) {
      for (int[] d2 : d1) Arrays.fill(d2, -1);
    }

    int d = word.charAt(0) - 'A', cost;
    dp[0][d][d] = 0;
    dp[0][d][N - 1] = 0;
    dp[0][N - 1][d] = 0;
    for (int i = 1; i < n; i++) {
      d = word.charAt(i) - 'A';
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          if (dp[i - 1][j][k] == -1) continue;
          // move finger 1
          cost = (j == N - 1) ? 0 : distance(d, j);
          cost += dp[i - 1][j][k];
          if (dp[i][d][k] == -1 || cost < dp[i][d][k]) dp[i][d][k] = cost;
          // move finger 2
          cost = (k == N - 1) ? 0 : distance(d, k);
          cost += dp[i - 1][j][k];
          if (dp[i][j][d] == -1 || cost < dp[i][j][d]) dp[i][j][d] = cost;
        }
      }
    }
    int ans = -1;
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (dp[n - 1][j][k] == -1) continue;
        if (ans == -1 || dp[n - 1][j][k] < ans) ans = dp[n - 1][j][k];
      }
    }
    return ans;
  }
}

