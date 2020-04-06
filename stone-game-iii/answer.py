class Solution:
    
    def array(self, a, val=None):
        return [val for _ in range(a)]

    def array2d(self, a, b, val=None):
        return [self.array(b, val=val) for _ in range(a)]
        
    def array3d(self, a, b, c, val=None):
        return [self.array2d(b, c, val=val) for _ in range(a)]

    def stoneGameIII(self, stoneValue: List[int]) -> str:
        n = len(stoneValue)
        MOD = 4
        dp = self.array(MOD, None)
        s = dp[n % MOD] = 0
        for i in range(n - 1, -1, -1):
            s += stoneValue[i]
            # pick 1
            val = s - dp[(i + 1) % MOD]
            # pick 2
            if i + 1 < n:
                val = max(val, s - dp[(i + 2) % MOD])
            # pick 3
            if i + 2 < n:
                val = max(val, s - dp[(i + 3) % MOD])
            dp[i % MOD] = val
        
        if dp[0] == s - dp[0]:
            return "Tie"
        return "Alice" if dp[0] > s - dp[0] else "Bob"

