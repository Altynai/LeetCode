import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.function.BiPredicate;

class Solution {
    private static int[] dx = new int[]{0, 1, 0, -1};
    private static int[] dy = new int[]{-1, 0, 1, 0};

    public int shortestPath(int[][] grid, int k) {
        final int n = grid.length;
        final int m = grid[0].length;
        final BiPredicate<Integer, Integer> inside = (x, y) -> (0 <= x && x < n && 0 <= y && y < m);
        k = Math.min(k, n + m - 1);
        final int[][][] dp = new int[n][m][k + 1];
        final PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(lh -> lh[0]));

        dp[0][0][k] = 1;
        pq.add(new int[]{dp[0][0][k], 0, 0, k});

        while (!pq.isEmpty()) {
            final int[] cur = pq.poll();
            if (cur[1] == n - 1 && cur[2] == m - 1)
                return cur[0] - 1;
            for (int i = 0; i < 4; i++) {
                int x = cur[1] + dx[i], y = cur[2] + dy[i];
                if (!inside.test(x, y))
                    continue;
                int d = cur[0] + 1;
                int r = cur[3] - grid[x][y];
                if (r < 0)
                    continue;
                if (dp[x][y][r] == 0 || d < dp[x][y][r]) {
                    dp[x][y][r] = d;
                    pq.add(new int[]{dp[x][y][r], x, y, r});
                }
            }
        }
        return -1;
    }
}
