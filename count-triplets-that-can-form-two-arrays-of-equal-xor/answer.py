from collections import defaultdict

class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        ans, n = 0, len(arr)
        for j in range(1, n):
            l, r = defaultdict(int), defaultdict(int)
            xor = 0
            for i in range(j - 1, -1, -1):
                xor ^= arr[i]
                l[xor] += 1
            xor = 0
            for k in range(j, n):
                xor ^= arr[k]
                r[xor] += 1
            for num, val in l.items():
                ans += val * r[num]
        return ans

