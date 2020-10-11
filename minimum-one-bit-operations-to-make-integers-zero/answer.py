class Solution:
    def minimumOneBitOperations(self, k: int) -> int:
        # a(n) = if n<2 then n else 2*m + (n mod 2 + m mod 2) mod 2, with m=a(floor(n/2)). - Reinhard Zumkeller, Aug 10 2010
        
        @lru_cache(None)
        def dfs(n):
            if n < 2:
                return n
            m = dfs(math.floor(n / 2.0))
            return 2 * m + (n % 2 + m % 2) % 2
        
        return dfs(k)
