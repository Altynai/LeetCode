
class Solution(object):
    def __init__(self):
        self.dx = [0, 1, 0, -1]
        self.dy = [1, 0, -1, 0]

    def spiralMatrixIII(self, R, C, r0, c0):
        """
        :type R: int
        :type C: int
        :type r0: int
        :type c0: int
        :rtype: List[List[int]]
        """
        path = set()
        vis = []
        cnt = R * C
        d = 0
        while len(vis) < cnt:
            path.add((r0, c0))
            if 0 <= r0 < R and 0 <= c0 < C:
                vis.append([r0, c0])
            r1 = r0 + self.dx[(d + 1) % 4]
            c1 = c0 + self.dy[(d + 1) % 4]
            # turn right
            if len(path) != 1 and (r1, c1) not in path:
                r0, c0, d = r1, c1, (d + 1) % 4
            # move forward
            else:
                r0, c0 = r0 + self.dx[d], c0 + self.dy[d]
        return vis

