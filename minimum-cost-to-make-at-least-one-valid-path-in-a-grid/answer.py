from collections import deque

class Solution:
    def minCost(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        seen = set()
        q = deque([(0, 0, 0)])
        while q:
            (i, j, step) = q.popleft()
            if i == n - 1 and j == m - 1:
                return step
            if (i, j) in seen:
                continue
            seen.add((i, j))
            for k, (x, y) in enumerate(zip((i, i, i + 1, i - 1), (j + 1, j - 1, j, j)), 1):
                if 0 <= x < n and 0 <= y < m and (x, y) not in seen:
                    q.appendleft((x, y, step)) if k == grid[i][j] else q.append((x, y, step + 1))
        return -1

