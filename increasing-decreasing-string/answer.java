class Solution {
  public String sortString(String s) {
    int n = s.length();
    final int m = 26;
    final StringBuilder sb = new StringBuilder();
    final int[] c = new int[m];
    for (int i = 0; i < n; i++) c[s.charAt(i) - 'a']++;
    while (n > 0) {
      for (int i = 0; i < m; i++) {
        if (c[i] > 0) {
          sb.append((char) ('a' + i));
          c[i]--;
          n--;
        }
      }
      for (int i = m - 1; i >= 0; i--) {
        if (c[i] > 0) {
          sb.append((char) ('a' + i));
          c[i]--;
          n--;
        }
      }
    }
    return sb.toString();
  }
}
