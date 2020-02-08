class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        s = sum(arr[:k - 1])
        threshold *= k
        ans = 0
        for i in range(k - 1, len(arr)):
            s = s + arr[i] - (arr[i - k] if i >= k else 0)
            if s >= threshold:
                ans += 1
        return ans

