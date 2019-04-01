class Solution:
        
    def numEnclaves(self, A: List[List[int]]) -> int:
        n, m = len(A), len(A[0])
        
        def clean(x, y):
            q = [(x, y)]
            A[x][y] = 0
            i = 0
            while i < len(q):
                x, y = q[i]
                for dx, dy in zip([0, 1, 0, -1], [1, 0, -1, 0]):
                    nx, ny = dx + x, dy + y
                    if 0 <= nx < n and 0 <= ny < m and A[nx][ny] == 1:
                        q.append((nx, ny))
                        A[nx][ny] = 0
                i += 1

        for j in range(m):
            if A[0][j] == 1:
                clean(0, j)
            if A[n - 1][j] == 1:
                clean(n - 1, j)

        for i in range(n):
            if A[i][0] == 1:
                clean(i, 0)
            if A[i][m - 1] == 1:
                clean(i, m - 1)
        
        return sum(sum(row) for row in A)

