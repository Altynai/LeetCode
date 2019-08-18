class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dis = [[grid[i][j] - 1 for j in range(m)] for i in range(n)]

        q = collections.deque(((i, j) for i in range(n) for j in range(m) if dis[i][j] == 0))
        while q:
            x, y = q.popleft()
            d = dis[x][y] + 1
            for dx, dy in zip((-1, 0, 1, 0), (0, 1, 0, -1)):
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and (dis[nx][ny] == -1 or d < dis[nx][ny]):
                    dis[nx][ny] = d
                    q.append((nx, ny))

        return max(dis[i][j] for i in range(n) for j in range(m)) or -1

