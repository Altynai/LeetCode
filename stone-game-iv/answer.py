from collections import defaultdict
from math import inf, sqrt

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

def init():
    n = 100000
    dp = array(n + 1, False)
    dp[1] = True
    for i in range(3, n + 1):
        j = 1
        while not dp[i] and j * j <= i:
            dp[i] |= not dp[i - j * j]
            j += 1
    return dp

class Solution:
    
    dp = init()

    def winnerSquareGame(self, n: int) -> bool:
        return self.dp[n]

