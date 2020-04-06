from math import sqrt

class Solution:
    def distance(self, x_center, y_center, x1, y1, x2, y2):
        px = x2 - x1
        py = y2 - y1
        norm = px * px + py * py

        u =  ((x_center - x1) * px + (y_center - y1) * py) / float(norm)
        if u > 1:
            u = 1
        elif u < 0:
            u = 0

        x = x1 + u * px
        y = y1 + u * py

        dx = x - x_center
        dy = y - y_center
        return sqrt(dx * dx + dy * dy)

    def checkOverlap(self, radius: int, x_center: int, y_center: int, x1: int, y1: int, x2: int, y2: int) -> bool:
        # center inside rectangle
        if x1 <= x_center <= x2 and y1 <= y_center <= y2:
            return True
        # distance between edge and center
        return min(
            self.distance(x_center, y_center, x1, y1, x1, y2),
            self.distance(x_center, y_center, x1, y1, x2, y1),
            self.distance(x_center, y_center, x2, y2, x2, y1),
            self.distance(x_center, y_center, x2, y2, x1, y2),
        ) <= radius

