from collections import defaultdict

class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        m = len(slices) // 3
        n = len(slices)

        def solve(i, j):
            dp = defaultdict(int)
            dp[(i, 0, False)] = 0
            dp[(i, 1, True)] = slices[i]
            for k in range(i + 1, j + 1):
                for c in range(m + 1):
                    # pick
                    if (k - 1, c - 1, False) in dp:
                        dp[(k, c, True)] = max(dp[(k, c, True)], dp[(k - 1, c - 1, False)] + slices[k])
                    # no pick
                    for status in (False, True):
                        if (k - 1, c, status) in dp:
                            dp[(k, c, False)] = max(dp[(k, c, False)], dp[(k - 1, c, status)])
            return max(dp[(j, m, False)], dp[(j, m, True)])

        return max(solve(0, n - 2), solve(1, n - 1))

