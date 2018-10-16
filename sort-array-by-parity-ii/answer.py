class Solution:
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        even = [a for a in A if a % 2 == 0]
        odd = [a for a in A if a % 2 != 0]
        ans = []
        for (a, b) in zip(even, odd):
            ans.extend([a, b])
        return ans

