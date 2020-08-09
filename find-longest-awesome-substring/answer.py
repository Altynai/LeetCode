from collections import defaultdict

class Solution:
    def longestAwesome(self, s: str) -> int:
        n = len(s)
        seen = defaultdict(int)

        ans = 0
        mask = 0
        for i in range(n):
            mask ^= 1 << int(s[i])
            if sum(1 for j in range(10) if (mask >> j) & 1) <= 1:
                ans = max(ans, i + 1)
            
            for j in range(10):
                mask2 = mask ^ (1 << j)
                if mask2 in seen:
                    ans = max(ans, i - seen[mask2])
            
            if mask in seen:
                ans = max(ans, i - seen[mask] + 1)
            else:
                seen[mask] = i

        return ans
