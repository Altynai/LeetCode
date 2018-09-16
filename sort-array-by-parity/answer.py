class Solution(object):
    def sortArrayByParity(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        a, b = [], []
        for e in A:
            c = a if e % 2 == 0 else b
            c.append(e)
        return a + b

