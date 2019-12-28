import java.util.List;
import java.util.function.BiPredicate;

class Solution {
    private final int MOD = 1000000000 + 7;
    private int[][] f;
    private int[][] g;

    private void update(int i, int j, int vf, int vg) {
        if (vf == f[i][j])
            g[i][j] = (g[i][j] + vg) % MOD;
        else if (vf > f[i][j]) {
            f[i][j] = vf;
            g[i][j] = vg;
        }
    }

    public int[] pathsWithMaxScore(List<String> board) {
        final int n = board.size();
        f = new int[n][n];
        g = new int[n][n];
        g[n - 1][n - 1] = 1;
        final BiPredicate<Integer, Integer> isObstacle = (i, j) -> board.get(i).charAt(j) == 'X';
        final BiPredicate<Integer, Integer> isValidState = (i, j) -> !isObstacle.test(i, j) && g[i][j] > 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (isObstacle.test(i, j)) {
                    continue;
                }
                int number = (i == 0 && j == 0) ? 0 : board.get(i).charAt(j) - '0';
                // left
                if (j + 1 < n && isValidState.test(i, j + 1))
                    update(i, j, f[i][j + 1] + number, g[i][j + 1]);
                // up
                if (i + 1 < n && isValidState.test(i + 1, j))
                    update(i, j, f[i + 1][j] + number, g[i + 1][j]);
                // diagonally
                if (i + 1 < n && j + 1 < n && isValidState.test(i + 1, j + 1))
                    update(i, j, f[i + 1][j + 1] + number, g[i + 1][j + 1]);
            }
        }
        return new int[]{f[0][0], g[0][0]};
    }
}
