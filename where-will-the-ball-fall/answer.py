class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        m = len(grid[0])
        
        def fall(c):
            for r in range(n):
                if grid[r][c] == 1:
                    if c + 1 >= m or grid[r][c + 1] == -1:
                        return -1
                    c += 1
                else:
                    if c <= 0 or grid[r][c - 1] == 1:
                        return -1
                    c -= 1
            return c
        
        return list(map(fall, range(m)))
