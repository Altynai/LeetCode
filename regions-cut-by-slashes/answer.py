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

    def id(self, p):
        r, c, i = p
        block = r * self.m + c
        return block * 4 + i

    def join(self, p1, p2):
        self.dsu.join(self.id(p1), self.id(p2))

    def regionsBySlashes(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """
        self.m = len(grid)
        n = self.m * self.m * 4
        self.dsu = DSU(n)

        for i in range(self.m):
            for j in range(self.m):
                if grid[i][j] == " ":
                    for k in range(3):
                        self.join((i, j, k), (i, j, k + 1))
                elif grid[i][j] == "/":
                    self.join((i, j, 0), (i, j, 1))
                    self.join((i, j, 2), (i, j, 3))
                else:
                    self.join((i, j, 0), (i, j, 3))
                    self.join((i, j, 1), (i, j, 2))
                
                if j + 1 < self.m:
                    self.join((i, j, 2), (i, j + 1, 0))
                if i + 1 < self.m:
                    self.join((i, j, 3), (i + 1, j, 1))
        
        return len(set(self.dsu.find(x) for x in range(n)))

