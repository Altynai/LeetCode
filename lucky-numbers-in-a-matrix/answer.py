class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        n, m = len(matrix), len(matrix[0])
        row = [min(matrix[i]) for i in range(n)]
        col = [max(matrix[k][j] for k in range(n)) for j in range(m)]
        return [
            matrix[i][j]
            for i in range(n)
            for j in range(m)
            if matrix[i][j] == row[i] and matrix[i][j] == col[j]
        ]

