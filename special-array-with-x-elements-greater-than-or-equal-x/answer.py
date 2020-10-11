class Solution:
    def specialArray(self, nums: List[int]) -> int:
        for i in range(1001):
            if sum(1 for a in nums if a >= i) == i:
                return i
        return -1

