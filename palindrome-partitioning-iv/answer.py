def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]

class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        dp = array2d(n, n, False)
        for i in range(n):
            dp[i][i] = True
        for i in range(n - 1):
            dp[i][i + 1] = (s[i] == s[i + 1])
        
        for m in range(3, n + 1):
            # i, i + 1, .. i + m - 2, i + m - 1 < n
            for i in range(n - m + 1):
                dp[i][i + m - 1] = dp[i + 1][i + m - 2] and (s[i] == s[i + m - 1])
        
        for i in range(n - 2):
            for j in range(i + 1, n - 1):
                # [0, i], [i + 1, j], [j + 1, n - 1]
                if dp[0][i] and dp[i + 1][j] and dp[j + 1][n - 1]:
                    return True
        return False

