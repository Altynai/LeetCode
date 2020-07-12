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

class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        dis = array(n, None)
        seen = array(n, False)
        g = defaultdict(list)
        for (u, v), w in zip(edges, succProb):
            g[u].append((v, w))
            g[v].append((u, w))
        
        dq = deque()
        dis[start] = 1.0
        dq.append(start)
        seen[start] = True
        
        while dq:
            u = dq.popleft()
            seen[u] = False
            for (v, w) in g[u]:
                w2 = dis[u] * w
                if dis[v] is None or w2 > dis[v]:
                    dis[v] = w2
                    if not seen[v]:
                        seen[v] = True
                        dq.append(v)
        
        return 0 if dis[end] is None else dis[end]

