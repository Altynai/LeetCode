class Solution {
  public int[][] matrixBlockSum(int[][] mat, int K) {
    final int n = mat.length;
    final int m = mat[0].length;
    final int[][] s = new int[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int val = mat[i - 1][j - 1];
        s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + val;
      }
    }
    final int[][] ans = new int[n][m];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int r2 = Math.min(n, i + K), c2 = Math.min(m, j + K);
        int r1 = Math.max(1, i - K), c1 = Math.max(1, j - K);
        ans[i - 1][j - 1] = s[r2][c2] - s[r2][c1 - 1] - s[r1 - 1][c2] + s[r1 - 1][c1 - 1];
      }
    }
    return ans;
  }
}

