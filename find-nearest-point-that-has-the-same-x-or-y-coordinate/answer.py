class Solution:
    def nearestValidPoint(self, x: int, y: int, points: List[List[int]]) -> int:
        valid = [
            (i, abs(x - a) + abs(y - b))
            for i, (a, b) in enumerate(points)
            if a == x or b == y
        ]
        if not valid:
            return -1
        mn = min(_[1] for _ in valid)
        for item in valid:
            if item[1] == mn:
                return item[0]
        return -1
