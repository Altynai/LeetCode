class Solution:
    def maxValueAfterReverse(self, nums: List[int]) -> int:
        n = len(nums)
        s = sum(abs(nums[i] - nums[i + 1]) for i in range(n - 1))
        extra = 0
        for i in range(n - 1):
            extra = max(extra, abs(nums[i + 1] - nums[0]) - abs(nums[i + 1] - nums[i]))
            extra = max(extra, abs(nums[n - 1] - nums[i]) - abs(nums[i + 1] - nums[i]))

        l, r = math.inf, -math.inf
        for i in range(n - 1):
            l = min(l, max(nums[i], nums[i + 1]))
            r = max(r, min(nums[i], nums[i + 1]))
        return s + max(extra, (r - l) * 2)

