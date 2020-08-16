class Solution:
    def minDays(self, n: int) -> int:
       
        @lru_cache(None)
        def dfs(m):
            if m <= 1:
                return m
            return 1 + min(m % 2 + dfs(m // 2), m % 3 + dfs(m // 3))

        return dfs(n)

