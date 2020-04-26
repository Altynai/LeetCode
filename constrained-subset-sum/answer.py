from collections import deque

class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = nums[0]
        dq = deque([(nums[0], 0)])
        for j in range(1, n):
            while dq and j - dq[0][1] > k:
                dq.popleft()
            val = dq[0][0] + nums[j] if dq and dq[0][0] > 0 else nums[j]
            ans = max(ans, val)
            while dq and dq[-1][0] < val:
                dq.pop()
            dq.append((val, j))
        return ans
