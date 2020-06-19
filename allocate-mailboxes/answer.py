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
    def minDistance(self, h: List[int], k: int) -> int:
        h.sort()
        n = len(h)
        dp = array(n, inf)
        
        cost = array2d(n, n, 0)
        for i in range(n):
            for j in range(i + 1, n):
                m = h[(i + j) // 2]
                for y in range(i, j + 1):
                    cost[i][j] += abs(m - h[y])

        for i in range(n):
            dp[i] = cost[0][i]

        for j in range(2, k + 1):
            dp2 = array(n, inf)
            for i in range(n):
                if dp[i] == inf:
                    continue
                for x in range(i + 1, n):
                    dp2[x] = min(dp2[x], dp[i] + cost[i + 1][x])
            dp = dp2

        return dp[n - 1]
            
