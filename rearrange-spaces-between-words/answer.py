class Solution:
    def reorderSpaces(self, s: str) -> str:
        m = s.count(' ')
        words = [w for w in s.split(' ') if w]
        n = len(words)
        if n == 1:
            each = 0
            left = m
        else:
            each = m // (n - 1)
            left = m % (n - 1)
        return (" " * each).join(words) + (" " * left)

