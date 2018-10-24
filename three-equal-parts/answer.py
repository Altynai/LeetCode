class Solution:

    NOT_FOUND = [-1, -1]

    def threeEqualParts(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """

        ones = [i for i, a in enumerate(A) if a == 1]
        n = len(ones)
        if n % 3 != 0:
            return self.NOT_FOUND
        
        m = n // 3
        if m == 0:
            return self.NOT_FOUND if len(A) < 3 else [0, 2]

        a = ones[:m]
        b = ones[m:m + m]
        c = ones[m + m:]
        
        for i in range(1, m):
            if not (a[i] - a[i - 1] == b[i] - b[i - 1] == c[i] - c[i - 1]):
                return self.NOT_FOUND
        
        zeros = len(A) - ones[-1]
        if b[0] - a[-1] < zeros or c[0] - b[-1] < zeros:
            return self.NOT_FOUND

        return [a[-1] + zeros - 1, b[-1] + zeros]

