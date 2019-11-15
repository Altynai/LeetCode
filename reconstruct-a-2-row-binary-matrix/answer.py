class Solution:
    def reconstructMatrix(self, upper: int, lower: int, colsum: List[int]) -> List[List[int]]:
        if sum(colsum) != upper + lower:
            return []
        n = len(colsum)
        ans = [[0] * n, [0] * n]
        for j in range(n):
            if colsum[j] == 2:
                ans[0][j] += 1
                ans[1][j] += 1
                upper -= 1
                lower -= 1
        for j in range(n):
            if colsum[j] == 1:
                if upper > 0:
                    ans[0][j] += 1
                    upper -= 1
                else:
                    ans[1][j] += 1
                    lower -= 1
        return ans if upper == 0 and lower == 0 else []

