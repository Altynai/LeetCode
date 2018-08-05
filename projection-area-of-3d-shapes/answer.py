class Solution(object):
    def projectionArea(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        n = len(grid)
        ans = 0
        for i in xrange(n):
            for j in xrange(n):
                ans += 1 if grid[i][j] else 0
        for i in xrange(n):
            ans += max(grid[i][j] for j in xrange(n))
        for j in xrange(n):
            ans += max(grid[i][j] for i in xrange(n))
        return ans

