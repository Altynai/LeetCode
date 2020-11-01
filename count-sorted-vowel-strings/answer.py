from collections import *
from math import *

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

class Solution:
    def countVowelStrings(self, n: int) -> int:
        dp = array(5, 1)
        for i in range(1, n):
            dp2 = array(5, 0)
            for j in range(5):
                for k in range(j + 1):
                    dp2[j] += dp[k]
            dp = dp2
        return sum(dp)
