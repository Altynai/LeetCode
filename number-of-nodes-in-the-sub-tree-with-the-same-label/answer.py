from collections import defaultdict, Counter
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
    def countSubTrees(self, n: int, edges: List[List[int]], labels: str) -> List[int]:
        g = defaultdict(list)
        for (u, v) in edges:
            g[u].append(v)
            g[v].append(u)
        
        ans = array(n, 0)

        def dfs(u, pa):
            cnt = Counter({labels[u]:1})
            for v in g[u]:
                if v == pa:
                    continue
                cnt += dfs(v, u)
            ans[u] = cnt[labels[u]]
            return cnt

        dfs(0, 0)
        return ans

