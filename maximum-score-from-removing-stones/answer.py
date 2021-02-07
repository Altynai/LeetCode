class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        p = sorted([a, b, c])
        ans = 0
        while p[1] > 0:
            ans += 1
            p[1] -= 1
            p[2] -= 1
            p.sort()
        return ans
