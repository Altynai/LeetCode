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
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        a = array(n + 1, inf)
        s = 0

        where = dict()
        where[0] = 0
        for i in range(1, n + 1):
            s += arr[i - 1]
            if (s - target) in where:
                a[i] = i - where[s - target]
            where[s] = i
            
        b = array(n + 1, inf)
        s = 0
        where = dict()
        where[0] = n + 1
        for i in range(n, 0, -1):
            s += arr[i - 1]
            if (s - target) in where:
                b[i] = where[s - target] - i
            where[s] = i
        
        c = array(n + 1, inf)
        c[n] = b[n]
        for i in range(n - 1, 0, -1):
            c[i] = min(b[i], c[i + 1])

        ans = inf
        for i in range(1, n):
            ans = min(ans, a[i] + c[i + 1])

        return -1 if ans == inf else ans

