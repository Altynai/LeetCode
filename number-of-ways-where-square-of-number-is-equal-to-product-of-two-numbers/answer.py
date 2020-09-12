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
    def numTriplets(self, a: List[int], b: List[int]) -> int:
        n = len(a)
        
        def cal():
            cnt = Counter(u * u for u in a)
            m = len(b)
            return sum(cnt[b[i] * b[j]] for i in range(m) for j in range(i + 1, m))
    
        ans = cal()
        a, b = b, a
        ans += cal()
        return ans

