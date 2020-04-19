class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        nums = [1, 1]
        while nums[-1] < 1000000000:
            nums.append(nums[-1] + nums[-2])
        
        n = len(nums)
        ans = 0
        for i in range(n - 1, -1, -1):
            while k >= nums[i]:
                k -= nums[i]
                ans += 1
        return ans

