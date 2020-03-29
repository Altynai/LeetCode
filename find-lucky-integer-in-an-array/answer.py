from collections import Counter

class Solution:
    def findLucky(self, arr: List[int]) -> int:
        c = list(v for k, v in Counter(arr).items() if k == v)
        return max(c) if c else -1

