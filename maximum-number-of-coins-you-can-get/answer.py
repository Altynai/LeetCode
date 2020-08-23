class Solution:
    def maxCoins(self, a: List[int]) -> int:
        a.sort()
        n = len(a)
        return sum(a[n - 2 * (i + 1)] for i in range(n // 3))

