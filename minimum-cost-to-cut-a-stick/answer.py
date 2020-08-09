class Solution:
    def minCost(self, n: int, c: List[int]) -> int:
        @lru_cache(None)
        def dp(l, r):
            ans = math.inf
            for pos in c:
                if l < pos < r:
                    ans = min(ans, r - l + dp(l, pos) + dp(pos, r))
            return 0 if ans == math.inf else ans

        return dp(0, n)
