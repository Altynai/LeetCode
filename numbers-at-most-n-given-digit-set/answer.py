class Solution(object):
    def atMostNGivenDigitSet(self, D, N):
        """
        :type D: List[str]
        :type N: int
        :rtype: int
        """
        S = str(N)
        n = len(S)
        m = len(D)
        dp = [0] * n + [1]

        for i in xrange(n - 1, -1, -1):
            for d in D:
                if d < S[i]:
                    dp[i] += m ** (n - 1 - i)
                elif d == S[i]:
                    dp[i] += dp[i + 1]

        return dp[0] + sum(m ** i for i in xrange(1, n, 1))

