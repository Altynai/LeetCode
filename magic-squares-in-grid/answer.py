class Solution(object):
    def magic(self, grid, i, j):
        numbers = {
            grid[i + di][j + dj]
            for di in xrange(3)
            for dj in xrange(3)
        }
        if numbers != set(xrange(1, 10)):
            return 0
        # row
        for di in xrange(3):
            if sum(grid[i + di][j:j+3]) != 15:
                return 0
        # column
        for dj in xrange(3):
            if grid[i][j + dj] + grid[i + 1][j + dj] + grid[i + 2][j + dj] != 15:
                return 0
        # diagonal
        if grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != 15:
            return 0
        elif grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != 15:
            return 0
        return 1

    def numMagicSquaresInside(self, grid):
        n, m = len(grid), len(grid[0])
        return sum(
            self.magic(grid, i, j)
            for i in xrange(0, n - 2)
            for j in xrange(0, m - 2)
        )

