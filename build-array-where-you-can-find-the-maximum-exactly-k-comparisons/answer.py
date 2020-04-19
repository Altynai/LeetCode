def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        dp = array2d(m + 1, k + 1, 0)
        dp[0][0] = 1
        mod = 1000000007
        
        for i in range(1, n + 1):
            dp2 = array2d(m + 1, k + 1, 0)

            for maxVal in range(0, m + 1):
                for incrLen in range(0, k + 1):
                    if dp[maxVal][incrLen] == 0:
                        continue
                    weight = dp[maxVal][incrLen]
                    # less or equal
                    for j in range(1, maxVal + 1):
                        dp2[maxVal][incrLen] = (dp2[maxVal][incrLen] + weight) % mod
                    # greater
                    if incrLen < k:
                        for j in range(maxVal + 1, m + 1):
                            dp2[j][incrLen + 1] = (dp2[j][incrLen + 1] + weight) % mod

            dp = dp2
        return sum(dp[maxVal][k] for maxVal in range(1, m + 1)) % mod

