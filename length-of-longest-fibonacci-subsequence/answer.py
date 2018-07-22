class Solution(object):
    def lenLongestFibSubseq(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        cache = {v: i for i, v in enumerate(A)}
        n, ans = len(A), 0
        for i in xrange(n):
            for j in xrange(i + 1, n):
                a, b = A[i], A[j]
                cnt, pre = 2, j
                while True:
                    c = a + b
                    index = cache.get(c)
                    if index and index > pre:
                        a, b = b, c
                        cnt += 1
                        pre = index
                    else:
                        break
                ans = ans if cnt < 3 else max(ans, cnt)
        return ans

