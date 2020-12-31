class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        s = s.lower()
        n = len(s)

        half = s[:n // 2]
        total = sum(s.count(ch) for ch in "aeiou")
        cnt = sum(half.count(ch) for ch in "aeiou") 
        return cnt * 2 == total

