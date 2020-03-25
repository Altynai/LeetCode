class Solution:
    def createTargetArray(self, nums: List[int], index: List[int]) -> List[int]:
        ans = []
        for num, i in zip(nums, index):
            ans.insert(i, num)
        return ans

