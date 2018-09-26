class Solution:
    def smallestRangeI(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        mx, mn = max(A), min(A)
        if mx - K <= mn + K:
            return 0
        return mx - K - mn - K

