from collections import defaultdict

class Solution:

    def chunks(self, size, nums):
        for i in range(0, len(nums), size):
            yield nums[i:i + size]

    def groupThePeople(self, groupSizes: List[int]) -> List[List[int]]:
        c = defaultdict(list)
        for i, n in enumerate(groupSizes):
            c[n].append(i)
        return [list(chunk) for size, nums in c.items() for chunk in self.chunks(size, nums)]

