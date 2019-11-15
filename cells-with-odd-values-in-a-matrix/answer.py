import collections

class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        r = collections.defaultdict(int)
        c = collections.defaultdict(int)
        for (i, j) in indices:
            r[i] += 1
            c[j] += 1
        return sum(
            (r[i] + c[j]) % 2
            for i in range(n)
            for j in range(m)
        )

