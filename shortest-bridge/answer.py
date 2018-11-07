class Solution:
    
    def shortestBridge(self, A):
        """
        :type A: List[List[int]]
        :rtype: int
        """
        dx = [0, 1, 0, -1]
        dy = [-1, 0, 1, 0]

        n = len(A)
        dis = [[-1 for i in range(n)] for j in range(n)]
        q = collections.deque()

        def valid(x, y):
            return 0 <= x < n and 0 <= y < n
    
        def dfs(x, y):
            dis[x][y] = 0
            q.append((x, y))
            for k in range(4):
                nx, ny = x + dx[k], y + dy[k]
                if valid(nx, ny) and dis[nx][ny] == -1 and A[nx][ny] == 1:
                    dfs(nx, ny)

        def run():
            for i in range(n):
                for j in range(n):
                    if A[i][j] == 1:
                        return dfs(i, j)

        def bfs():
            while q:
                x, y = q.popleft()
                for k in range(4):
                    nx, ny = x + dx[k], y + dy[k]
                    if not valid(nx, ny):
                        continue
                    elif dis[nx][ny] != -1:
                        continue
                    elif A[nx][ny] == 1:
                        return dis[x][y]
                    else:
                        dis[nx][ny] = dis[x][y] + 1
                        q.append((nx, ny))
            return 1
            
        run()
        return bfs()

