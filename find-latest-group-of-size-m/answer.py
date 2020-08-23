from collections import defaultdict

class DSU:
    def __init__(self, n):
        self.n = n
        self.fa = list(range(n))
        self.sz = [1 for _ in range(n)]
        self.cnt = defaultdict(int)

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
            if self.sz[x] > self.sz[y]:
                x, y = y, x
            sx = self.sz[x]
            sy = self.sz[y]
            self.cnt[sx] -= 1
            self.cnt[sy] -= 1
            self.cnt[sx + sy] += 1
            
            self.fa[x] = y
            self.sz[y] += self.sz[x]

class Solution:
    def findLatestStep(self, a: List[int], m: int) -> int:
        n = len(a)
        b = [0 for _ in range(n + 2)]
        dsu = DSU(n + 1)
        
        ans = -1
        for step, j in enumerate(a, 1):
            b[j] = 1
            dsu.cnt[1] += 1

            if b[j - 1]:
                dsu.join(j, j - 1)
            if b[j + 1]:
                dsu.join(j, j + 1)
            if dsu.cnt.get(m, 0):
                ans = step

        return ans
