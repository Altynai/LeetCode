from collections import Counter

class Solution:
    def minSetSize(self, arr: List[int]) -> int:
        n = len(arr)
        a = sorted(((v, k) for k, v in Counter(arr).items()), reverse=True)
        cnt, total = 0, 0
        for i in range(len(a)):
            total += a[i][0]
            cnt += 1
            if total >= n // 2:
                break
        return cnt

