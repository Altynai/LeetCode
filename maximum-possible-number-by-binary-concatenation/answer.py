class Solution:
    def cal(self, x, y, z):
        s = f"{x:b}{y:b}{z:b}"
        return int(s, 2)

    def maxGoodNumber(self, a: List[int]) -> int:
        return max(
            self.cal(a[0], a[1], a[2]),
            self.cal(a[0], a[2], a[1]),
            self.cal(a[1], a[0], a[2]),
            self.cal(a[1], a[2], a[0]),
            self.cal(a[2], a[0], a[1]),
            self.cal(a[2], a[1], a[0]),
        )
