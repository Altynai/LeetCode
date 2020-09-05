from collections import defaultdict
from math import inf

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]


class Solution:
    def minDays(self, a: List[List[int]]) -> int:
        n, m = len(a), len(a[0])
        vis = array2d(n, m, 0)

        def dfs(x, y):
            vis[x][y] = 1
            for dx, dy in zip((0, 1, 0, -1), (1, 0, -1, 0)):
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and a[nx][ny] == 1 and vis[nx][ny] == 0:
                    dfs(nx, ny)

        def count():
            cnt = 0
            for x in range(n):
                for y in range(m):
                    if a[x][y] == 1 and vis[x][y] == 0:
                        cnt += 1
                        dfs(x, y)
            return cnt
        
        if count() != 1:
            return 0
        
        for x in range(n):
            for y in range(m):
                if a[x][y] == 1:
                    vis = array2d(n, m, 0)
                    a[x][y] = 0
                    if count() != 1:
                        return 1
                    a[x][y] = 1
        return 2

