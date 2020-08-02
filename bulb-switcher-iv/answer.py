class Solution:
    def minFlips(self, t: str) -> int:
        n = len(t)
        flip = 0
        ans = 0
        for i in range(n):
            val = '1' if flip else '0'
            if t[i] != val:
                ans += 1
                flip ^= 1
        return ans

