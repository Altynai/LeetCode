class Solution {
    public int countSquares(int[][] matrix) {
        final int n = matrix.length, m = matrix[0].length;
        int[][] s = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int w = matrix[i - 1][j - 1];
                s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + w;
            }
        }

        int ans = 0;
        for (int k = 1; k <= Math.min(n, m); k++) {
            int square = k * k;
            for (int i = 1, i2; (i2 = i + k - 1) <= n; i++) {
                for (int j = 1, j2; (j2 = j + k - 1) <= m; j++) {
                    if (s[i2][j2] - s[i2][j - 1] - s[i - 1][j2] + s[i - 1][j - 1] == square)
                        ans++;
                }
            }
        }
        return ans;
    }
}
