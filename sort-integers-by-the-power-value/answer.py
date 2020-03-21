class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:
        dp = {1: 0}

        def dfs(u):
            if u in dp:
                return dp[u]
            dp[u] = dfs(u // 2) + 1 if u % 2 == 0 else dfs(u * 3 + 1) + 1
            return dp[u]

        return sorted((dfs(i), i) for i in range(lo, hi + 1))[k - 1][1]

