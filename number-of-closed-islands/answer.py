class Solution:
    
    def dfs(self, i, j):
        self.vis.add((i, j))
        if i == 0 or i == self.n - 1 or j == 0 or j == self.m - 1:
            self.flag = 0

        for (di, dj) in zip((0, 1, 0, -1), (1, 0, -1, 0)):
            ni, nj = i + di, j + dj
            if 0 <= ni < self.n and 0 <= nj < self.m and self.grid[ni][nj] == 0 and (ni, nj) not in self.vis:
                self.dfs(ni, nj)

    def closedIsland(self, grid: List[List[int]]) -> int:
        self.grid = grid
        self.n, self.m = len(grid), len(grid[0])
        self.vis = set()
        self.flag = 1
        ans = 0

        for i in range(1, self.n - 1):
            for j in range(1, self.m - 1):
                if grid[i][j] == 0 and (i, j) not in self.vis:
                    self.flag = 1
                    self.dfs(i, j)
                    ans += self.flag
        return ans

