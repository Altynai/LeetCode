class Solution:
    def orangesRotting(self, grid: 'List[List[int]]') -> 'int':
        n, m = len(grid), len(grid[0])
        seen = set()
        minutes = 0
        
        dq = collections.deque()
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 2:
                    dq.append((i, j, 0))
                    seen.add((i, j))
        
        while dq:
            (x, y, mins) = dq.popleft()
            minutes = max(minutes, mins)

            for dx, dy in ((0, -1), (0, 1), (1, 0), (-1, 0)):
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and (nx, ny) not in seen and grid[nx][ny] == 1:
                    grid[nx][ny] = 2
                    dq.append((nx, ny, mins + 1))
                    seen.add((nx, ny))
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 1:
                    return -1
        return minutes

