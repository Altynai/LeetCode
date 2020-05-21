class Solution:
    def getIntercetions(self, x0, y0, r0, x1, y1, r1):
        # circle 1: (x0, y0), radius r0
        # circle 2: (x1, y1), radius r1

        d = math.sqrt((x1 - x0)**2 + (y1 - y0)**2)

        # non intersecting
        if d > r0 + r1:
            return None
        # One circle within other
        if d < abs(r0 - r1):
            return None
        # coincident circles
        if d == 0 and r0 == r1:
            return None
        else:
            a = (r0**2 - r1**2 + d**2) / (2 * d)
            h = math.sqrt(r0**2 - a**2)
            x2 = x0 + a * (x1 - x0) / d
            y2 = y0 + a * (y1 - y0) / d
            x3 = x2 + h * (y1 - y0) / d
            y3 = y2 - h * (x1 - x0) / d

            x4 = x2 - h * (y1 - y0) / d
            y4 = y2 + h * (x1 - x0) / d

            return (x3, y3, x4, y4)

    def numPoints(self, points: List[List[int]], r: int) -> int:
        n = len(points)
        ans = 1

        for i in range(n):
            x0, y0 = points[i]
            for j in range(n):
                if i == j:
                    continue
                x1, y1 = points[j]
                p = self.getIntercetions(x0, y0, r, x1, y1, r)
                if p is None:
                    continue

                x2, y2, x3, y3 = p
                ans1, ans2 = 0, 0
                for k in range(n):
                    xk, yk = points[k]
                    if (x2 - xk)**2 + (y2 - yk)**2 <= r**2:
                        ans1 += 1
                    if (x3 - xk)**2 + (y3 - yk)**2 <= r**2:
                        ans2 += 1

                ans = max(ans, ans1)
                ans = max(ans, ans2)

        for i in range(n):
            x0, y0 = points[i]
            ans1 = 0
            for j in range(n):
                x1, y1 = points[j]
                if (x0 - x1)**2 + (y0 - y1)**2 <= r**2:
                    ans1 += 1
            ans = max(ans, ans1)
        return ans

