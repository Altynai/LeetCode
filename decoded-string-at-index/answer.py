class Solution(object):
    def decodeAtIndex(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        a = []
        for i in xrange(len(S)):
            if S[i].isdigit():
                d = int(S[i])
                if isinstance(a[-1], int):
                    a[-1] *= d
                else:
                    a.append(d)
            else:
                if a and isinstance(a[-1], unicode):
                    a[-1] += S[i]
                else:
                    a.append(S[i])

        b = []
        n = 0
        for i in xrange(len(a)):
            if i == 0 or isinstance(a[i], unicode):
                n += len(a[i])
            else:
                n *= a[i]
            b.append(n)
            if n >= K:
                break

        for i in xrange(len(b) - 1, -1, -1):
            if isinstance(a[i], unicode):
                j = 0 if i == 0 else b[i - 1]
                if j < K <= j + len(a[i]):
                    return a[i][K - j - 1]
            else:
                j = b[i - 1]
                K = j if K % j == 0 else K % j
        return ""

