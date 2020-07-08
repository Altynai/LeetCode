from collections import *
from math import inf

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]


class Fenwick:

    def __init__(self, n):
        self.c = [0 for _ in range(n + 1)]
        self.n = n
    
    def update(self, i, val):
        while i <= self.n:
            self.c[i] += val
            i += i & (-i)

    def sum(self, i):
        ans = 0
        while i > 0:
            ans += self.c[i]
            i -= i & (-i)
        return ans

class Solution:
    def minInteger(self, num: str, k: int) -> str:
        n = len(num)
        if k >= n * (n - 1) // 2:
            s = list(num)
            s.sort()
            return ''.join(s)

        fw = Fenwick(n + 1)
        used = array(n + 1, False)
        where = defaultdict(deque)
        for i, digit in enumerate(num, 1):
            where[int(digit)].append(i)

        ans = []
        fixed = 0
        while fixed < n and k > 0:
            for d in range(10):
                if not where[d]:
                    continue
                first = where[d][0]
                cnt = fw.sum(first)
                swaps = first - cnt - 1
                if k >= swaps:
                    k -= swaps
                    ans.append(str(d))
                    where[d].popleft()
                    used[first] = True
                    fw.update(first, 1)
                    fixed += 1
                    break
            else:
                break
        
        for i in range(1, n + 1):
            if not used[i]:
                ans.append(num[i - 1])

        return ''.join(ans)

