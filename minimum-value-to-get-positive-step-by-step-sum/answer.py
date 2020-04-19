class Solution:
    def minStartValue(self, nums: List[int]) -> int:
        val, cur = nums[0], nums[0]
        for i in range(1, len(nums)):
            cur += nums[i]
            val = min(val, cur)
        return 1 if val >= 0 else 1 - val

