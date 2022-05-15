class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        s = str(num)
        n = len(s)
        ans = 0
        for i in range(0, n - k + 1):
            x = int(s[i : i + k])
            if x > 0 and num % x == 0:
                ans += 1
        return ans
