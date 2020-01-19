class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        rs = [(max(i - r, 0), min(i + r, n)) for i, r in enumerate(ranges) if r != 0]
        rs.sort(key=lambda r: (r[0], -r[1]))
        if not rs or rs[0][0] != 0:
            return -1
        
        ans, p, m, i = 1, rs[0][1], len(rs), 1
        while i < m:
            j, q = i, p
            while j < m and rs[j][0] <= p:
                j, q = j + 1, max(q, rs[j][1])
            if q > p:
                ans, i, p = ans + 1, j, q
            else:
                break
        return -1 if p < n else ans

