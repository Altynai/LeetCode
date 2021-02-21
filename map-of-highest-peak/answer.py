from collections import *
from math import *
from heapq import *

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]


class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        n, m = len(isWater), len(isWater[0])
        
        h = array2d(n, m, -1)
        q = deque()
        for i in range(n):
            for j in range(m):
                if isWater[i][j]:
                    h[i][j] = 0
                    q.append((i, j))
        
        dx = (0, 1, -1, 0)
        dy = (1, 0, 0, -1)
        while q:
            (i, j) = q.popleft()
            for k in range(4):
                x = dx[k] + i
                y = dy[k] + j
                if 0 <= x < n and 0 <= y < m and h[x][y] == -1:
                    h[x][y] = h[i][j] + 1
                    q.append((x, y))
        return h

