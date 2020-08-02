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
    def getWinner(self, a: List[int], k: int) -> int:
        n = len(a)
        mx = max(a)
        
        i = 0
        cnt = defaultdict(int)
        for j in range(1, n):
            cnt[max(a[i], a[j])] += 1
            if a[j] > a[i]:
                i = j
            j += 1
            if a[i] == mx or cnt[a[i]] == k:
                return a[i]
        return mx

