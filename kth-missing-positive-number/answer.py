class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        a = set(arr)
        cnt = 0
        for i in range(1, 2001):
            if i not in a:
                cnt += 1
                if cnt == k:
                    return i
        return -1

