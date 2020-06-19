class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        ans = []
        n = len(nums)
        s = 0
        for i in range(n):
            s += nums[i]
            ans.append(s)
        return ans
