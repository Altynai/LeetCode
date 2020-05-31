def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        dp = array2d(m, m, None)
        dp[0][m - 1] = grid[0][0] + grid[0][m - 1]
        
        for i in range(1, n):
            dp2 = array2d(m, m, None)
            
            for j in range(m):
                for k in range(m):
                    if dp[j][k] is None:
                        continue
                    for j2 in (j - 1, j, j + 1):
                        for k2 in (k - 1, k, k + 1):
                            if j2 < 0 or j2 >= m or k2 < 0 or k2 >= m:
                                continue
                            val = grid[i][j2] if j2 == k2 else grid[i][j2] + grid[i][k2]
                            val += dp[j][k]
                            if dp2[j2][k2] is None or val > dp2[j2][k2]:
                                dp2[j2][k2] = val

            dp = dp2

        ans = 0
        for j in range(m):
            for k in range(m):
                if dp[j][k] is not None:
                    ans = max(ans, dp[j][k])
        return ans

