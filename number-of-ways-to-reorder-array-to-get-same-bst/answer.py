from collections import defaultdict
from math import comb

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

class Solution:
    def numOfWays(self, a: List[int]) -> int:
        n = len(a)
        bst = array2d(n + 1, 2, None)

        for i in range(1, n):
            r = a[0]
            while True:
                idx = 0 if a[i] < r else 1
                if bst[r][idx] is None:
                    bst[r][idx] = a[i]
                    break
                else:
                    r = bst[r][idx]

        mod = 1000000000 + 7

        def dfs(r):
            if r is None:
                return (0, 1)

            size_left, cnt_left = dfs(bst[r][0])
            size_right, cnt_right = dfs(bst[r][1])
            total = size_left + size_right
            
            cnt = comb(total, size_left) % mod
            cnt =  cnt * cnt_left % mod
            cnt =  cnt * cnt_right % mod

            return (total + 1, cnt)
            
        m, ans = dfs(a[0])
        assert(m == n)
        return (ans - 1 + mod) % mod

