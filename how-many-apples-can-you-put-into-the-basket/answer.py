class Solution:
    def maxNumberOfApples(self, arr: List[int]) -> int:
        arr.sort()
        total = 5000
        ans = 0
        for apple in arr:
            if total >= apple:
                ans += 1
                total -= apple
        return ans

