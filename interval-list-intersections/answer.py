# Definition for an interval.
# class Interval:
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution:
    def intersection(self, a, b):
        if a.end < b.start or b.end < a.start:
            return None
        return Interval(max(a.start, b.start), min(a.end, b.end))

    def intervalIntersection(self, A: 'List[Interval]', B: 'List[Interval]') -> 'List[Interval]':
        n, m = len(A), len(B)
        if n + m == 0:
            return []

        vals = []
        for i in range(n):
            for j in range(m):
                isn = self.intersection(A[i], B[j])
                if isn is not None:
                    vals.append(isn)

        vals.sort(key=lambda x: (x.start, x.end))
        ans = vals[:1]
        for i in range(1, len(vals)):
            ok = True
            while self.intersection(ans[-1], vals[i]):
                ok = False
                ans[-1] = (min(ans[-1].start, vals[i].start), max(ans[-1].end, vals[i].end))
            if ok:
                ans.append(vals[i])
        return ans

