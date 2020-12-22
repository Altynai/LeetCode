class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        pfx = sfx = 0
        n = len(nums)
        for i in range(1, n):
            sfx += nums[i]
            
        ans = []
        for i in range(n):
            if i > 0:
                sfx -= nums[i]
            val = 0 if i == 0 else i * nums[i] - pfx
            val += sfx - (n - 1 - i) * nums[i]
            ans.append(val)
            pfx += nums[i]

        return ans

