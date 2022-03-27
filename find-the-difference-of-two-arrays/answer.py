class Solution:
    def findDifference(self, a: List[int], b: List[int]) -> List[List[int]]:
        sa = set(a)
        sb = set(b)
        return [list(sa - sb), list(sb - sa)]

