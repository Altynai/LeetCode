class Solution:
    def getMinDistSum(self, positions: List[List[int]]) -> float:
        
        def distance(pa, pb):
            dx, dy = pa[0] - pb[0], pa[1] - pb[1]
            return sqrt(dx * dx + dy * dy)
    
        def cal(x, y):
            return sum(distance((x, y), p) for p in positions)
        
        n = len(positions)
        x = sum(p[0] for p in positions) / n
        y = sum(p[1] for p in positions) / n
        ans = cal(x, y)

        step = 1000
        while step > 1e-6:
            for dx, dy in zip((0, 1, 0, -1), (1, 0, -1, 0)):
                nx = x + step * dx
                ny = y + step * dy
                nv = cal(nx, ny)
                if nv < ans:
                    x, y, ans = nx, ny, nv
                    break
            else:
                step /= 2
        
        return ans

