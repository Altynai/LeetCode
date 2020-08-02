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
    def maxNumOfSubstrings(self, s: str) -> List[str]:
        maxn = 26
        n = len(s)
        g = defaultdict(set)
        l = array(maxn, -1)
        r = array(maxn, -1)
        
        chars = set()
        for i in range(n):
            j = ord(s[i]) - ord('a')
            l[j] = i if l[j] == -1 else l[j]
            r[j] = i
            chars.add(j)
        
        for i in range(n):
            j = ord(s[i]) - ord('a')
            for k in chars:
                if j != k and l[k] <= i <= r[k]:
                    # if k is picked, j is also picked
                    g[k].add(j)
        
        def dfs(u, dep):
            dep.add(u)
            for v in g[u]:
                if v not in dep:
                    dfs(v, dep)
            return dep
            
        ranges = set()
        for i in chars:
            dep = dfs(i, set())
            ranges.add((min(l[j] for j in dep), max(r[j] for j in dep)))

        ranges = list(ranges)
        ranges.sort(key=lambda e: e[1] - e[0])
        ans = []
        # greedy on smallest range first
        for l2, r2 in ranges:
            if any(max(l1, l2) <= min(r1, r2) for l1, r1 in ans):
                continue
            ans.append((l2, r2))
        return [s[l2:r2 + 1] for l2, r2 in ans]

