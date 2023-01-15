class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        return sum(nums) - sum(sum(map(int, str(x))) for x in nums)
