class Solution:
    def tupleSameProduct(self, nums: List[int]) -> int:
        cnt = collections.defaultdict(int)
        n = len(nums)
        for i in range(n):
            for j in range(i):
                cnt[nums[i] * nums[j]] += 1
        
        ans = 0
        for p, group in cnt.items():
            if group >= 2:
                ans += group * (group - 1) * 4
        return ans
