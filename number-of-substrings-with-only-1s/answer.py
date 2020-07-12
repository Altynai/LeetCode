class Solution:
    def numSub(self, s: str) -> int:
        n = len(s)
        j, ans = 0, 0
        mod = 1000000000 + 7
        while j < n:
            while j < n and s[j] == "0":
                j += 1
            cnt = 0
            while j < n and s[j] == "1":
                j += 1
                cnt += 1
            ans += (cnt + 1) * cnt // 2
            ans %= mod
        return ans

