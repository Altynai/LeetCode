class Solution:
    def longestSubarray(self, a: List[int]) -> int:
        n = len(a)
        if sum(a) == n:
            return n - 1

        i, j = 0, 0
        pi, pj = None, None
        ans = 0
        while j < n:
            while j < n and a[j] == 0:
                j += 1
            i = j
            while j < n and a[j] == 1:
                j += 1
            if i < n:
                ans = max(ans, j - i)
                if pj is not None and pj + 1 == i:
                    ans = max(ans, j - pi - 1)
                pi, pj = i, j
        return ans

