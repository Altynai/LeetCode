class Solution(object):
    def smallestRangeII(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        n = len(A)
        A.sort()
        ans = A[n - 1] - A[0]
        
        for i in xrange(1, n):
            a = A[n - 1] - K
            b = A[0] + K
            c = A[n - i] - K
            d = A[n - i - 1] + K
            
            mx = max(a, d)
            mn = min(b, c)
            ans = min(ans, mx - mn)
        
        return ans

