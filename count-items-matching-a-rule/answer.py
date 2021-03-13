class Solution:
    def countMatches(self, items: List[List[str]], k: str, v: str) -> int:
        ans = 0
        for (t, c, n) in items:
            if k == 'type' and v == t:
                ans += 1
            elif k == 'color' and v == c:
                ans += 1
            elif k == 'name' and v == n:
                ans += 1
        return ans
