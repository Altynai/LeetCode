def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

class Solution:
    def numberOfArrays(self, s: str, k: int) -> int:
        t = [0] + list(map(int, s))
        n = len(t)
        dp = array(n, 0)
        dp[0] = 1
        mod = 1000000000 + 7

        for i in range(1, n):
            if dp[i - 1] == 0 or t[i] == 0:
                continue
            j, val = i, t[i]
            while val <= k and j < n:
                dp[j] = (dp[j] + dp[i - 1]) % mod
                if j + 1 >= n:
                    break
                val = val * 10 + t[j + 1]
                j += 1
        return dp[n - 1]

