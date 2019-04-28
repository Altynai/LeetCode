class Solution {
    private static int[] dx = {0, 1, 0, -1};
    private static int[] dy = {1, 0, -1, 0};

    private int[][] grid;
    private int n, m;
    private int preColor;
    private int nxtColor;
    private boolean[][] seen;

    private void init(int[][] grid, int r0, int c0, int color) {
        this.grid = grid;
        this.n = grid.length;
        this.m = grid[0].length;
        this.preColor = grid[r0][c0];
        this.nxtColor = color;
        this.seen = new boolean[n][m];
    }

    private boolean isBoard(int x, int y) {
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1)
            return true;
        for (int k = 0; k < 4; k++) {
            int color = grid[x + dx[k]][y + dy[k]];
            if (color != preColor && color != nxtColor)
                return true;
        }
        return false;
    }

    private void dfs(int x, int y) {
        seen[x][y] = true;
        if (isBoard(x, y))
            grid[x][y] = nxtColor;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || seen[nx][ny] || grid[nx][ny] != preColor)
                continue;
            dfs(nx, ny);
        }
    }

    public int[][] colorBorder(int[][] grid, int r0, int c0, int color) {
        init(grid, r0, c0, -1);
        dfs(r0, c0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                grid[i][j] = (grid[i][j] == -1) ? color : grid[i][j];
        }
        return grid;
    }
}
