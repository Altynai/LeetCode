def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n, m = len(nums1), len(nums2)
        inf = 1000 * 1000 * 500 + 1
        dp = array2d(n + 1, m + 1, val=-inf)

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                val = nums1[i - 1] * nums2[j - 1]
                dp[i][j] = max(dp[i][j], val, dp[i - 1][j - 1] + val, dp[i - 1][j], dp[i][j - 1])

        return dp[n][m]

