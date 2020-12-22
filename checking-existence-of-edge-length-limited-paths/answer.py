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
    def distanceLimitedPathsExist(self, n: int, edgeList: List[List[int]], queries: List[List[int]]) -> List[bool]:
        nq = len(queries)
        queries = [(lim, u, v, i) for i, (u, v, lim) in enumerate(queries)]
        queries.sort()
        
        edgeList.sort(key=lambda e: e[2])
        ne = len(edgeList)
        
        ans = [False for _ in range(nq)]
        dsu = DSU(n)
        j = 0

        for (lim, u, v, i) in queries:
            while j < ne and edgeList[j][2] < lim:
                dsu.join(edgeList[j][0], edgeList[j][1])
                j += 1
            
            ans[i] = dsu.find(u) == dsu.find(v)
        
        return ans
