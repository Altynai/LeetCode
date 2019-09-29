import queue

class Solution:

    DX = [0, 1, 0, -1]
    DY = [1, 0, -1, 0]
    
    def minimumMoves(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        pq = queue.PriorityQueue()
        cache = {(0, 0, 0): 0}
        pq.put((0, 0, 0, 0))  # (step, x, y, direction)

        def updateCache(state, step):
            val = cache.get(state, -1)
            if val == -1 or step < val:
                cache[state] = step
                return True
            return False

        def valid(x, y):
            return 0 <= x < n and 0 <= y < m and grid[x][y] == 0

        while not pq.empty():
            step, x, y, direction = pq.get()
            if x == n - 1 and y == m - 2 and direction == 0:
                return step
            # move right and down
            for ndirection in (0, 1):
                tx, ty = x + self.DX[ndirection], y + self.DY[ndirection]
                hx, hy = tx + self.DX[direction], ty + self.DY[direction]
                if valid(tx, ty) and valid(hx, hy) and updateCache((tx, ty, direction), step + 1):
                    pq.put((step + 1, tx, ty, direction))
            # clockwise
            tx, ty = x + self.DX[1], y + self.DY[1]
            hx, hy = tx + self.DX[direction], ty + self.DY[direction]
            if direction == 0 and valid(tx, ty) and valid(hx, hy):
                ndirection = (direction + 1) % 4
                hx, hy = x + self.DX[ndirection], y + self.DY[ndirection]
                if valid(hx, hy) and updateCache((x, y, ndirection), step + 1):
                    pq.put((step + 1, x, y, ndirection))
            # counterclockwise
            tx, ty = x + self.DX[0], y + self.DY[0]
            hx, hy = tx + self.DX[direction], ty + self.DY[direction]
            if direction == 1 and valid(tx, ty) and valid(hx, hy):
                ndirection = (direction + 3) % 4
                hx, hy = x + self.DX[ndirection], y + self.DY[ndirection]
                if valid(hx, hy) and updateCache((x, y, ndirection), step + 1):
                    pq.put((step + 1, x, y, ndirection))
        return -1

