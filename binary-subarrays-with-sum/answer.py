class Solution:

    def onlyZero(self, A):
        n = len(A)
        ans = cnt = 0
        for i in range(n):
            if A[i] == 0:
                cnt += 1
            else:
                ans += cnt + (cnt * (cnt - 1) // 2)
                cnt = 0
        ans += cnt + (cnt * (cnt - 1) // 2)
        cnt = 0
        return ans

    def numSubarraysWithSum(self, A, S):
        """
        :type A: List[int]
        :type S: int
        :rtype: int
        """
        if S == 0:
            return self.onlyZero(A)

        n = len(A)
        ones = [i for i in range(n) if A[i] == 1]
        
        m = len(ones)
        ans = 0
        for j in range(S - 1, m):
            i = j - S + 1
            l = ones[0] + 1 if i == 0 else ones[i] - ones[i - 1]
            r = n - ones[m - 1] if j == m - 1 else ones[j + 1] - ones[j]
            ans += l * r
        return ans

