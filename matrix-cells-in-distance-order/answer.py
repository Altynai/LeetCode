class Solution:
    def allCellsDistOrder(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        points = [
            (abs(i - r0) + abs(j - c0), i, j)
            for i in range(R)
            for j in range(C)
        ]
        points.sort()
        return [[p[1], p[2]] for p in points]

