class Solution {
    static int[][] DELTA = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int[][] grid;
    int n;
    int m;
    boolean[][] visited;
    int ans;

    public int getMaximumGold(int[][] grid) {
        this.grid = grid;
        n = grid.length;
        m = grid[0].length;
        visited = new boolean[n][m];
        ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0)
                    dfs(i, j, 0);
            }
        }
        return ans;
    }

    private void dfs(int i, int j, int sum) {
        visited[i][j] = true;
        ans = Math.max(ans, sum + grid[i][j]);
        for (int k = 0; k < 4; k++) {
            int ni = i + DELTA[k][0];
            int nj = j + DELTA[k][1];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] > 0 && !visited[ni][nj]) {
                dfs(ni, nj, sum + grid[i][j]);
            }
        }
        visited[i][j] = false;
    }
}
