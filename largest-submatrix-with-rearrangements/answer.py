class Solution:
    def largestSubmatrix(self, mat: List[List[int]]) -> int:
        n, m = len(mat), len(mat[0])
        h = [0 for _ in range(m)]
        ans = 0
        
        row = [0 for _ in range(m)]
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 0:
                    h[j] = 0
                else:
                    h[j] += 1
                row[j] = h[j]
            
            row.sort()
            for j in range(m):
                ans = max(ans, row[j] * (m - j))
        return ans
