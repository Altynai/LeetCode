class Solution:
    def maxWidthOfVerticalArea(self, p: List[List[int]]) -> int:
        p.sort()
        n = len(p)
        return max(p[i][0] - p[i - 1][0] for i in range(1, n))

