class Solution:
    def canMouseWin(self, grid: List[str], catJump: int, mouseJump: int) -> bool:
        n, m = len(grid), len(grid[0])
        dx = [0, 1, -1, 0]
        dy = [1, 0, 0, -1]
        maxStep = n * m * 2
        
        @lru_cache(None)
        def dfs(mx, my, cx, cy, turn):
            # mouse move
            if turn % 2 == 0:
                if (mx, my) == (cx, cy):
                    return False
                if turn > maxStep:
                    return False
                if grid[mx][my] == "F":
                    return True
                if grid[cx][cy] == "F":
                    return False
                
                for k in range(4):
                    for step in range(mouseJump + 1):
                        nx = mx + dx[k] * step
                        ny = my + dy[k] * step
                        if nx < 0 or nx >= n or ny < 0 or ny >= m:
                            break
                        if grid[nx][ny] == "#":
                            break
                        
                        if not dfs(nx, ny, cx, cy, turn + 1):
                            return True
                return False

            # cat move
            else:
                if (mx, my) == (cx, cy):
                    return True
                if turn > maxStep:
                    return True
                if grid[mx][my] == "F":
                    return False
                if grid[cx][cy] == "F":
                    return True
                
                for k in range(4):
                    for step in range(catJump + 1):
                        nx = cx + dx[k] * step
                        ny = cy + dy[k] * step
                        if nx < 0 or nx >= n or ny < 0 or ny >= m:
                            break
                        if grid[nx][ny] == "#":
                            break
                        
                        if not dfs(mx, my, nx, ny, turn + 1):
                            return True
                return False

        cx = cy = -1
        mx = my = -1
        for i in range(n):
            for j in range(m):
                if grid[i][j] == "C":
                    cx = i
                    cy = j
                elif grid[i][j] == "M":
                    mx = i
                    my = j

        return dfs(mx, my, cx, cy, 0)

