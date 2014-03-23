
class Solution:
    __slot__ = ("_result", "_mark", "_n", "_column_status", "_hash")

    def __init__(self):
        self._hash = {(1 << i):i for i in xrange(16)}

    def makeBoard(self):
        result = list()
        for i in xrange(self._n):
            row = list()
            for j in xrange(self._n):
                row.append('Q') if self._mark[i] & (1 << j) else row.append('.')
            result.append(''.join(row))
        return result

    def canPutQueueAt(self, x, y):
        # has a queue in the same row
        if self._mark[x]:
            return False
        # has a queue in the same column
        if self._column_status & (1 << y):
            return False
        # has a queue in the same diagonal
        for k in xrange(min(x, y) + 1):
            i, j = x - k, y - k
            if (self._mark[i] & (1 << j)):
                return False
        for k in xrange(min(x, self._n - y) + 1):
            i, j = x - k, y + k
            if (self._mark[i] & (1 << j)):
                return False
        return True

    def lock(self, i, j):
        self._mark[i] ^= (1 << j)
        self._column_status ^= (1 << j)

    def relase(self, i, j):
        self._mark[i] ^= (1 << j)
        self._column_status ^= (1 << j)

    def dfs(self, index):
        if (index == self._n):
            self._result.append(self.makeBoard())
            return
        mask = (1 << self._n) - 1 - self._column_status
        i = index
        while mask:
            j = self._hash[mask & (-mask)]
            mask -= mask & (-mask)
            if self.canPutQueueAt(i, j):
                self.lock(i, j)
                self.dfs(index + 1)
                self.relase(i, j)

    # @return a list of lists of string
    def totalNQueens(self, n):
        self._n = n
        self._result = []
        self._mark = [0 for _ in xrange(n)]
        self._column_status = 0
        self.dfs(0)
        return len(self._result)
        
