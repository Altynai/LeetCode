class Solution:

    def solve(self, c):
        for i in range(1, self.n):
            if self.A[i][c] < self.A[i - 1][c]:
                return 1
        return 0
        
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        self.A = A
        self.n = len(A)
        self.m = len(A[0])
        return sum(map(self.solve, range(self.m)))

