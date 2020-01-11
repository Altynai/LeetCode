import java.util.HashSet;
import java.util.Set;

class Solution {
  private boolean equals(final String text, int step, int i, int j) {
    for (int k = 0; k < step; k++) {
      if (text.charAt(i + k) != text.charAt(j + k)) return false;
    }
    return true;
  }

  public int distinctEchoSubstrings(String text) {
    final int n = text.length();
    final int[][] h = new int[n][n + 1];
    final int[] p = new int[n + 1];
    final int mod = 1000000000 + 7;
    p[0] = 31;
    for (int i = 1; i <= n; i++) {
      p[i] = p[i - 1] * 31 % mod;
    }
    for (int step = 1; step <= n; step++) {
      for (int i = 0; i + step - 1 < n; i++) {
        h[i][step] = (h[i][step - 1] + (text.charAt(i) - 'a' + 1) * p[step]) % mod;
      }
    }
    final Set<String> ans = new HashSet<>();
    for (int step = 1; step <= n / 2; step++) {
      for (int i = 0; i + 2 * step - 1 < n; i++) {
        if (h[i][step] == h[i + step][step] && equals(text, step, i, i + step))
          ans.add(text.substring(i, i + step));
      }
    }
    return ans.size();
  }
}

