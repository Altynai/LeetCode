import java.util.Arrays;

class KMP {
  public int[] lps;
  public String pattern;

  public KMP(String pattern) {
    int m = pattern.length();
    int[] lps = new int[m];
    for (int i = 1, j = 0; i < m; ) {
      if (pattern.charAt(i) == pattern.charAt(j)) lps[i++] = ++j;
      else {
        if (j == 0) lps[i++] = 0;
        else j = lps[j - 1];
      }
    }
    this.pattern = pattern;
    this.lps = lps;
  }

  int search(String text) {
    int n = text.length();
    for (int i = 0, j = 0; i < n; ) {
      if (text.charAt(i) == pattern.charAt(j)) {
        i++;
        j++;
      } else {
        if (j == 0) i++;
        else j = lps[j - 1];
      }
      if (j == pattern.length()) return i - pattern.length();
    }
    return -1;
  }
}

class Solution {
  private static final int MOD = 1000000000 + 7;

  private int add(int a, int b) {
    int c = (int) (((long) a + b) % MOD);
    return (c + MOD) % MOD;
  }

  public int findGoodStrings(int n, String s1, String s2, String evil) {
    int[] lps = new KMP(evil).lps;
    int ans = add(solve(s2, evil, lps), -solve(s1, evil, lps));
    if (!s1.contains(evil)) ans = add(ans, 1);
    return ans;
  }

  private int solve(String s, String evil, int[] lps) {
    int n = s.length(), m = evil.length();
    int[][][] dp = new int[n][m][2];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) Arrays.fill(dp[i][j], -1);
    }
    // init pos 0
    for (char ch = 'a'; ch <= s.charAt(0); ch++) {
      int cp = ch == evil.charAt(0) ? 1 : 0;
      int eq = ch == s.charAt(0) ? 1 : 0;
      if (cp == m) continue;
      if (dp[0][cp][eq] == -1) dp[0][cp][eq] = 0;
      dp[0][cp][eq]++;
    }

    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 2; k++) {
          if (dp[i][j][k] == -1) continue;

          char end = k == 1 ? s.charAt(i + 1) : 'z';
          for (char ch = 'a'; ch <= end; ch++) {
            // match evil
            int j2 = j;
            while (j2 > 0 && evil.charAt(j2) != ch) j2 = lps[j2 - 1];
            if (evil.charAt(j2) == ch) j2++;
            if (j2 == m) continue;
            int k2 = (k == 1 && ch == s.charAt(i + 1)) ? 1 : 0;
            if (dp[i + 1][j2][k2] == -1) dp[i + 1][j2][k2] = 0;
            dp[i + 1][j2][k2] = add(dp[i + 1][j2][k2], dp[i][j][k]);
          }
        }
      }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < 2; k++) {
        if (dp[n - 1][j][k] == -1) continue;
        ans = add(ans, dp[n - 1][j][k]);
      }
    }
    return ans;
  }
}

