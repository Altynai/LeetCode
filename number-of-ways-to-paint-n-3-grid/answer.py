from itertools import product

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

class Solution:
    def numOfWays(self, n: int) -> int:
        mod = 1000000000 + 7
        colors = range(3)
        dp = array3d(3, 3, 3, 0)
        for i, j, k in product(colors, repeat=3):
            dp[i][j][k] = 1 if (i != j and j != k) else 0

        for w in range(1, n):
            dp2 = array3d(3, 3, 3, 0)
            for i, j, k in product(colors, repeat=3):
                if dp[i][j][k] == 0:
                    continue
                for i2, j2, k2 in product(colors, repeat=3):
                    if i2 == j2 or j2 == k2 or i == i2 or j == j2 or k == k2:
                        continue
                    dp2[i2][j2][k2] = (dp2[i2][j2][k2] + dp[i][j][k]) % mod
            dp = dp2

        return sum(dp[i][j][k] for i, j, k in product(colors, repeat=3)) % mod

