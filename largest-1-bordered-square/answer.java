import java.util.stream.Stream;

class Solution {
    public int largest1BorderedSquare(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        int[][] c = new int[n + 1][m + 1];
        for (int j = 1; j <= m; j++) {
            for (int i = 1; i <= n; i++)
                c[i][j] = c[i - 1][j] + grid[i - 1][j - 1];
        }
        int[][] r = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)
                r[i][j] = r[i][j - 1] + grid[i - 1][j - 1];
        }
        int ans = 0;
        for (int j = 1; j <= n; j++) {
            for (int i = 1; i <= j; i++) {
                int len = j - i + 1, k2;
                for (int k = 1; (k2 = k + len - 1) <= m; k++) {
                    ans = Stream.of(
                            c[j][k] - c[i - 1][k],
                            c[j][k2] - c[i - 1][k2],
                            r[i][k2] - r[i][k - 1],
                            r[j][k2] - r[j][k - 1]
                    ).allMatch(x -> x == len) ? Math.max(ans, len * len) : ans;
                }
            }
        }
        return ans;
    }
}
