class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        return sum(1 for a in arr1 if all(abs(a - b) > d for b in arr2))

