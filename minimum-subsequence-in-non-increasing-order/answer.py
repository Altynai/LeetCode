class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)
        tot = sum(nums)
        n, cur = len(nums), 0
        for i in range(n):
            cur += nums[i]
            if cur > tot - cur:
                return nums[:i + 1]
        return []

