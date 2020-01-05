import java.util.Arrays;

class Solution {
  public int minInsertions(String s) {
    final int n = s.length();
    int[][] dp = new int[n][n + 1];
    for (int i = 0; i < n; i++) dp[i][1] = 0;
    for (int i = 0; i + 1 < n; i++) dp[i][2] = (s.charAt(i) == s.charAt(i + 1)) ? 0 : 1;

    for (int j = 3; j <= n; j++) {
      for (int i = 0; i + j - 1 < n; i++) {
        final int k = i + j - 1;
        if (s.charAt(i) == s.charAt(k)) dp[i][j] = dp[i + 1][j - 2];
        else dp[i][j] = Math.min(dp[i][j - 1], dp[i + 1][j - 1]) + 1;
      }
    }
    return dp[0][n];
  }
}

