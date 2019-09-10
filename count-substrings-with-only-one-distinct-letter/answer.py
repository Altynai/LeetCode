class Solution:
    def countLetters(self, S: str) -> int:
        ans, cnt = 0, 1
        for i in range(1, len(S)):
            if S[i] == S[i - 1]:
                cnt += 1
            else:
                ans += cnt * (cnt + 1) // 2
                cnt = 1
        return ans + cnt * (cnt + 1) // 2

