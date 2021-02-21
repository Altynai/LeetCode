class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        n = len(groups)
        m = len(nums)
        j = 0
        for i in range(n):
            k = len(groups[i])
            while j < m and groups[i] != nums[j:j+k]:
                j += 1
            if j == m:
                return 0
            j += len(groups[i])
        return 1

