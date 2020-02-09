from collections import Counter

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        c = Counter(arr)
        return any(c.get(0, 0) > 1 if k == 0 else c.get(k + k, 0) for k in c.keys())

