class Solution:
    def minOperations(self, n: int) -> int:
        return sum(n - (i * 2 + 1) for i in range(n) if i * 2 + 1 < n)

