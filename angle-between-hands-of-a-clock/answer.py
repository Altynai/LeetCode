class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        h = (hour % 12 + minutes / 60) * 30
        m = minutes * 6
        return min(abs(h - m), 360.0 - abs(h - m))

