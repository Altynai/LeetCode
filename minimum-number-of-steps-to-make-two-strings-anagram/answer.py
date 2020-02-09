from collections import Counter

class Solution:
    def minSteps(self, s: str, t: str) -> int:
        d = Counter(s) - Counter(t)
        return sum(v for v in d.values() if v > 0)

