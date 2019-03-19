class Solution:
    def dfs(self, s, seen, start):
        N = int(s)
        first = int(s[0])

        less = first - sum((1 for i in seen if i < first), 0)
        if len(s) == 1:
            return less

        ans = 0
        available = 10 - len(seen) - 1
        if start:
            less -= 1

        for i in range(1, len(s)):
            less *= available
            available -= 1
        ans += less

        if first in seen:
            return ans

        seen.add(first)
        ans += self.dfs(s[1:], seen, False)
        return ans

    def countByLength(self, l):
        if l < 1:
            return 0
        ans, available = 9, 9
        while l > 1:
            ans *= available
            available -= 1
            l -= 1
        return ans

    def numDupDigitsAtMostN(self, N: int) -> int:
        if N < 10:
            return 0

        s = str(N)
        ans = 0
        for l in range(len(s)):
            ans += self.countByLength(l)

        seen = set()
        ans += self.dfs(s, seen, True)
        if len(set(s)) == len(s):
            ans += 1
        return N - ans

