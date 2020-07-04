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
    def canArrange(self, arr: List[int], k: int) -> bool:
        cnt = array(k, 0)
        for val in arr:
            cnt[(val % k + k) % k] += 1
        
        if cnt[0] % 2 == 1:
            return False
        i, j = 1, k - 1
        while i <= j:
            if cnt[i] != cnt[j]:
                return False
            i += 1
            j -= 1
        return True
