import math

class Solution:
    def isGoodArray(self, nums: List[int]) -> bool:
        ans = nums[0]
        for i in range(1, len(nums)):
            ans = math.gcd(ans, nums[i])
        return ans == 1

