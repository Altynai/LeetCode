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
    def minNumberOperations(self, a: List[int]) -> int:
        n = len(a)
        dp = array(n, 0)
        dp[0] = a[0]
        for i in range(1, n):
            dp[i] = dp[i - 1]
            if a[i] > a[i - 1]:
                dp[i] += a[i] - a[i - 1]
        return dp[n - 1]

