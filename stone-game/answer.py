class Solution(object):
    def prepare(self, piles):
        self.n = len(piles)
        self.piles = piles
        self.sum = [piles[0]]
        for i in xrange(1, self.n):
            self.sum.append(self.sum[i - 1] + piles[i])
        self.cache = [
            [-1 for j in xrange(self.n)]
            for i in xrange(self.n)
        ]

    def sumup(self, i, j):
        if i == 0:
            return self.sum[j]
        return self.sum[j] - self.sum[i - 1]

    def dfs(self, i, j):
        if self.cache[i][j] != -1:
            return self.cache[i][j]
        elif i == j:
            s = self.sumup(i, i)
            self.cache[i][i] = s
            return s

        left = self.piles[i] + self.sumup(i + 1, j) - self.dfs(i + 1, j)
        right = self.piles[j] + self.sumup(i, j - 1) - self.dfs(i, j - 1)
        self.cache[i][j] = max(left, right)
        return self.cache[i][j]

    def stoneGame(self, piles):
        """
        :type piles: List[int]
        :rtype: bool
        """
        self.prepare(piles)
        total = self.sumup(0, self.n - 1)
        maxn = self.dfs(0, self.n - 1)
        return maxn > total - maxn

