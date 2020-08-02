class Solution:
    def countOdds(self, low: int, high: int) -> int:
        def cal(n):
            return 0 if n <= 0 else (n + 1) // 2
        return cal(high) - cal(low - 1)

