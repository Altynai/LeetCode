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
    def numOfSubarrays(self, a: List[int]) -> int:
        n = len(a)
        mod = 1000000000 + 7
        
        ps = array(n + 1, 0)
        for i in range(n):
            ps[i + 1] = ps[i] + a[i]
        
        cnt = defaultdict(int)
        cnt[0] = 1
        ans = 0
        for i in range(1, n + 1):
            ans = (ans + cnt[(ps[i] % 2) ^ 1]) % mod
            cnt[ps[i] % 2] += 1
        return ans

