class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        ans, cur = 0, 0
        n = len(s)
        i, j = 0, 0
        while j < n:
            if s[j] in "aeiou":
                cur += 1
            j += 1
            while j - i > k:
                if s[i] in "aeiou":
                    cur -= 1
                i += 1
            ans = max(ans, cur)
        return ans

