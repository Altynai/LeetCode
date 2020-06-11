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
    def minCost(self, h: List[int], cost: List[List[int]], n: int, m: int, target: int) -> int:
        dp = array2d(m + 1, target + 1, val=inf)
        if h[0] > 0:
            dp[h[0]][1] = 0
        else:
            for c in range(1, m + 1):
                dp[c][1] = cost[0][c - 1]
        
        for i in range(1, n):
            dp2 = array2d(m + 1, target + 1, val=inf)
            for c in range(1, m + 1):
                for t in range(1, target + 1):

                    for nc in ([h[i]] if h[i] > 0 else range(1, m + 1)):
                        nt = t if nc == c else t + 1
                        if nt > target:
                            continue
                        w = 0 if nc == h[i] else cost[i][nc - 1]
                        dp2[nc][nt] = min(dp2[nc][nt], dp[c][t] + w)
            dp = dp2
        
        ans = min(dp[c][target] for c in range(1, m + 1))
        return -1 if ans == inf else ans

