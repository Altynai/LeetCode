class Solution:
    def diagonalSum(self, a: List[List[int]]) -> int:
        n = len(a)
        ans = sum(a[i][i] + a[n - 1 - i][i] for i in range(n))
        if n & 1:
            ans -= a[n // 2][n // 2]
        return ans

