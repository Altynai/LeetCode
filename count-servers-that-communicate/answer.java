class Solution {
    private int[][] grid;
    private int n, m;
    private boolean[][] vis;
    private int count;

    public int countServers(int[][] grid) {
        this.grid = grid;
        n = grid.length;
        m = grid[0].length;
        vis = new boolean[n][m];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    count = 0;
                    dfs(i, j);
                    ans += (count > 1) ? count : 0;
                }
            }
        }
        return ans;
    }

    private void dfs(int x, int y) {
        vis[x][y] = true;
        count++;
        for (int j = 0; j < m; j++) {
            if (grid[x][j] == 1 && !vis[x][j])
                dfs(x, j);
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][y] == 1 && !vis[i][y])
                dfs(i, y);
        }
    }
}
