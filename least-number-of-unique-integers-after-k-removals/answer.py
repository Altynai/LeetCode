from collections import Counter

class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        b = [[v, k] for k, v in Counter(arr).items()]
        b.sort()
        
        i = 0
        n = len(b)
        while i < n and k > 0:
            if k >= b[i][0]:
                k -= b[i][0]
                i += 1
            else:
                k = 0
        return n - i

