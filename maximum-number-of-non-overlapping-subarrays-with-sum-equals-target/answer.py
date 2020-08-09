class Solution:
    def maxNonOverlapping(self, a: List[int], t: int) -> int:
        seen = {0}
        ans = 0
        s = 0
        for b in a:
            s += b
            if s - t in seen:
                ans += 1
                seen = set()
            seen.add(s)
        return ans
