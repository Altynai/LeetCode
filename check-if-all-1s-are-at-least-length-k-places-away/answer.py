class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        last = - k - 1
        for i in range(n):
            if nums[i] == 0:
                continue
            elif i - last - 1 < k:
                return False
            else:
                last = i
        return True

