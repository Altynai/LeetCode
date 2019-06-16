import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;
        int[][] dis = new int[n][n];
        for (int[] di : dis)
            Arrays.fill(di, -1);

        Queue<int[]> queue = new ArrayDeque<>();
        if (grid[0][0] == 0) {
            dis[0][0] = 1;
            queue.add(new int[]{0, 0});
        }

        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int x = cur[0], y = cur[1];
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0)
                        continue;
                    int nx = x + i, ny = y + j;
                    if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                        continue;
                    if (grid[nx][ny] == 1)
                        continue;
                    int d = dis[x][y] + 1;
                    if (dis[nx][ny] == -1 || d < dis[nx][ny]) {
                        dis[nx][ny] = d;
                        queue.add(new int[]{nx, ny});
                    }
                }
            }
        }
        return dis[n - 1][n - 1];
    }
}
