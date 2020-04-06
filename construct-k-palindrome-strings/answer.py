from collections import Counter

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        c = Counter(s)
        even = sum(v // 2 for v in c.values())
        odd = sum(v % 2 for v in c.values())
        if odd > k or even * 2 + odd < k:
            return False
        return True

