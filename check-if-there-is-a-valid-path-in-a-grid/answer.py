class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        dx = [-1, 0, 1, 0]
        dy = [0, 1, 0, -1]
        n, m = len(grid), len(grid[0])
        dg = {
            1: {1, 3},
            2: {0, 2},
            3: {2, 3},
            4: {1, 2},
            5: {0, 3},
            6: {0, 1},
        }
        seen = set()

        def connected(sa, sb, k):
            if k not in sa:
                return False
            op = (k + 2) % 4
            return k in sb or op in sb

        def dfs(i, j):
            seen.add((i, j))
            for k in dg[grid[i][j]]:
                ni, nj = i + dx[k], j + dy[k]
                if not (0 <= ni < n and 0 <= nj < m) or (ni, nj) in seen:
                    continue
                if connected(dg[grid[i][j]], dg[grid[ni][nj]], k):
                    dfs(ni, nj)

        dfs(0, 0)
        return (n - 1, m - 1) in seen

