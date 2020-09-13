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
    def minCostConnectPoints(self, p: List[List[int]]) -> int:
        n = len(p)
        e = []
        for i in range(n):
            for j in range(n):
                if i == j:
                    continue
                d = abs(p[i][0] - p[j][0]) + abs(p[i][1] - p[j][1])
                e.append((d, i, j))
        
        e.sort()
        
        dsu = DSU(n)
        had = 0
        ans = 0
        for (d, i, j) in e:
            if dsu.find(i) != dsu.find(j):
                ans += d
                dsu.join(i, j)
                had += 1
            if had == n - 1:
                break
        return ans
        
