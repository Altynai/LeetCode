from collections import Counter

class Solution:
    def countLargestGroup(self, n: int) -> int:
        c = Counter(sum(map(int, str(i))) for i in range(1, n + 1))
        size = max(c.values())
        return sum(1 for v in c.values() if size == v)

