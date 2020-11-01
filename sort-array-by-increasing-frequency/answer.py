
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        cnt = collections.Counter(nums)
        items = [(v, -k) for k, v in cnt.items()]
        items.sort()
        return [-k for v, k in items for _ in range(v)]

