def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

class Solution:
    def ways(self, pizza: List[str], k: int) -> int:

        def add(a, b):
            return (b if a == -1 else a + b) % 1000000007

        n, m = len(pizza), len(pizza[0])
        dp = array3d(n + 1, m + 1, k, -1)
        s = array2d(n + 1, m + 1, 0)
        
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                val = 1 if pizza[i - 1][j - 1] == 'A' else 0
                s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + val
        
        def hasApple(i1, j1, i2, j2):
            return s[i2][j2] - s[i1 - 1][j2] - s[i2][j1 - 1] + s[i1 - 1][j1 - 1] > 0

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if hasApple(i, j, n, m):
                    dp[i][j][0] = 1
        
        for cut in range(k - 1):
            for i in range(1, n + 1):
                for j in range(1, m + 1):
                    if dp[i][j][cut] == -1:
                        continue
                    # left
                    for sj in range(1, j):
                        if hasApple(i, sj, n, j - 1):
                            dp[i][sj][cut + 1] = add(dp[i][sj][cut + 1], dp[i][j][cut])
                    # upper 
                    for si in range(1, i):
                        if hasApple(si, j, i - 1, m):
                            dp[si][j][cut + 1] = add(dp[si][j][cut + 1], dp[i][j][cut])
        
        if dp[1][1][k - 1] == -1:
            return 0
        return dp[1][1][k - 1]

