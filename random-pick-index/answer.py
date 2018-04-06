class Solution(object):

    def __init__(self, nums):
        """
        
        :type nums: List[int]
        :type numsSize: int
        """
        self.nums = nums
        

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        count, response = 0, -1
        for index, num in enumerate(self.nums):
            if num != target:
                continue
            count += 1
            if count == 1:
                response = index
            else:
                if random.randint(0, count - 1) == 0:
                    response = index
        return response

# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)