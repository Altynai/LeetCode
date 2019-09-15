class Solution:

    def maxSubArray(self, arr: List[int]) -> int:
        ans, sum = arr[0], 0
        for i in arr:
            sum += i
            ans = max(ans, sum)
            sum = max(sum, 0)
        return ans

    def maxEndpoint(self, arr: List[int], fromLeft: bool) -> int:
        ans, sum = 0, 0
        arr2 = arr if fromLeft else reversed(arr)
        for i in arr2:
            sum += i
            ans = max(ans, sum)
        return ans

    def kConcatenationMaxSum(self, arr: List[int], k: int) -> int:
        if max(arr) <= 0:
            return 0
        mod = 1_000_000_007
        total = sum(arr)
        mx = self.maxSubArray(arr)
        ml, mr = self.maxEndpoint(arr, True), self.maxEndpoint(arr, False)
        if total > 0:
            return max(total * k, total * (k - 1) + ml, total * (k - 1) + mr, total * (k - 2) + ml + mr) % mod
        return max(mx, ml + mr, ml, mr) % mod

