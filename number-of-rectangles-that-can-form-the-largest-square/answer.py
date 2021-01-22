class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        lens = [min(l, w) for (l, w) in rectangles]
        mx = max(lens)
        return sum(1 for l in lens if l == mx)

