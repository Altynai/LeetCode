class Solution:
    def checkIfCanBreak(self, s1: str, s2: str) -> bool:
        a, b = sorted(s1), sorted(s2)
        n = len(a)
        return all(a[i] >= b[i] for i in range(n)) or \
            all(b[i] >= a[i] for i in range(n))

