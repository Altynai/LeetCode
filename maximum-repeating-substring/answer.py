class Solution:
    def maxRepeating(self, s: str, word: str) -> int:
        ans = 0
        t = word
        while s.find(t) != -1:
            ans += 1
            t += word
        return ans

