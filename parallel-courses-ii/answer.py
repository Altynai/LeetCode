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
    def minNumberOfSemesters(self, n: int, edges: List[List[int]], k: int) -> int:
        g = defaultdict(list)
        ind = array(n, 0)
        for (u, v) in edges:
            u -= 1
            v -= 1
            g[u].append(v)
            ind[v] += 1

        seen = set()
        for i in range(1, n + 1):
            ids = [u for u in range(n) if ind[u] == 0 and u not in seen]
            ids.sort(key=lambda u: len(g[u]), reverse=True)
            for j in range(min(k, len(ids))):
                v = ids[j]
                seen.add(v)
                for w in g[v]:
                    ind[w] -= 1
            if len(seen) == n:
                return i
        return -1
