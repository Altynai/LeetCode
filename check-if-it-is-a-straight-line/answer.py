class Solution:
    def checkStraightLine(self, coordinates: List[List[int]]) -> bool:
        n = len(coordinates)
        x0, y0 = coordinates[0]
        for i in range(1, n):
            x1, y1 = coordinates[i]
            for j in range(i + 1, n):
                x2, y2 = coordinates[j]
                if (x1 - x0) * (y2 - y0) != (x2 - x0) * (y1 - y0):
                    return False
        return True
                
