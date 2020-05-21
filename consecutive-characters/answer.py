class Solution:
    def maxPower(self, s: str) -> int:
        p = ""
        n, ans = len(s), 1
        i, j = 0, 0
        while j < n:
            if s[j] == p:
                ans = max(ans, j - i + 1)
            else:
                i, p = j, s[j]
            j += 1
        return ans

