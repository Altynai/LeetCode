class Solution:
    def check(self, nums: List[int]) -> bool:
        n = len(nums)
        k = 0
        for i in range(n):
            if nums[i] > nums[(i + 1) % n]:
                k += 1
        return k <= 1

