class Solution:
    def minDifference(self, a: List[int]) -> int:
        a.sort()
        n = len(a)
        ans = inf
        for l, r in product(range(4), range(4)):
            if l + r > 3 or l + r >= n:
                continue
            ans = min(ans, a[n - 1 - r] - a[l])
        return ans

