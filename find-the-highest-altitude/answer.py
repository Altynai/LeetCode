class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        now = ans = 0
        for g in gain:
            now += g
            ans = max(ans, now)
        return ans
