class Solution:
    def round(self, num, divisor):
        return num / divisor if num % divisor == 0 else int(round(num / divisor + 0.5))

    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        l = 1
        r = max(nums)
        ans = -1
        while l <= r:
            m = (l + r) >> 1
            if sum(self.round(num, m) for num in nums) <= threshold:
                ans = m
                r = m - 1
            else:
                l = m + 1
        return ans

