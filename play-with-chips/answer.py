class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        c = [0, 0]
        for chip in chips:
            c[chip % 2] += 1
        return min(c)

