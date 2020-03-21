from collections import defaultdict

class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: List[List[int]]) -> int:
        seated = defaultdict(set)
        for (a, b) in reservedSeats:
            seated[a].add(b)
        ans = 0
        for ids in seated.values():
            count = sum(1 for s in (2, 6) if all(j not in ids for j in range(s, s + 4)))
            if count == 0 and all(j not in ids for j in range(4, 8)):
                count += 1
            ans += count
        return ans + 2 * (n - len(seated))

