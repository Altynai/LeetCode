class Solution {

  private static final int base = 37;
  private static final int mod = 1000000000 + 7;
  private String text;
  private int n;
  private int[][] h;

  private boolean same(int i, int j, int len) {
    if (h[i][len] != h[j][len]) {
      return false;
    }
    for (int k = 0; k < len; k++) {
      if (text.charAt(i + k - 1) != text.charAt(j + k - 1)) {
        return false;
      }
    }
    return true;
  }

  public int longestDecomposition(String text) {
    this.text = text;
    n = text.length();
    h = new int[n + 1][n + 1];

    for (int j = 1; j <= n; j++) {
      for (int i = 1; i + j - 1 <= n; i++) {
        h[i][j] = (h[i][j - 1] * base + text.charAt(i + j - 2) - 'a') % mod;
      }
    }

    int[] dp = new int[n + 1];
    dp[0] = 1;
    int ans = 1;
    for (int i = 1; i <= n / 2; i++) {
      for (int j = i; j <= n / 2; j++) {
        int len = j - i + 1;
        int k = n - j + 1;
        int extra = j * 2 < n ? 1 : 0;
        if (dp[i - 1] > 0 && same(i, k, len)) {
          dp[j] = Math.max(dp[j], dp[i - 1] + 1);
        }
        ans = Math.max(ans, (dp[j] - 1) * 2 + extra);
      }
    }
    return ans;
  }
}
