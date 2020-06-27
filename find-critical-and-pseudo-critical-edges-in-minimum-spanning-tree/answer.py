class DSU:
    def __init__(self, n):
        self.n = n
        self.fa = list(range(n))

    def find(self, x):
        r = x
        while self.fa[r] != r:
            r = self.fa[r]
        i = x
        while i != r:
            i, self.fa[i] = self.fa[i], r
        return r
    
    def join(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x != y:
            self.fa[x] = y

class Solution:
    
    def mst(self, n, e, ignored=None, force=None):
        dsu = DSU(n)
        ans = 0
        cnt = 0
        for w, u, v, i in e:
            if i == force:
                if dsu.find(u) != dsu.find(v):
                    ans += w
                    cnt += 1
                    dsu.join(u, v)

        for w, u, v, i in e:
            if i == ignored or i == force:
                continue
            if dsu.find(u) != dsu.find(v):
                ans += w
                cnt += 1
                dsu.join(u, v)

        return -1 if cnt != n - 1 else ans

    def findCriticalAndPseudoCriticalEdges(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        e = [(w, u, v, i) for i, (u, v, w) in enumerate(edges)]
        e.sort()
        mn = self.mst(n, e, None, None)

        ans = [[], []]
        seen = set()
        for i in range(len(e)):
            val = self.mst(n, e, i, None)
            if val == -1 or val > mn:
                ans[0].append(i)
                seen.add(i)

        for i in range(len(e)):
            if i not in seen and self.mst(n, e, None, i) == mn:
                ans[1].append(i)
        return ans
                
