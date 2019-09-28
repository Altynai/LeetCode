class Solution:
    def minimumAbsDifference(self, arr: List[int]) -> List[List[int]]:
        arr.sort()
        n = len(arr)
        diff = arr[1] - arr[0]
        for i in range(2, n):
            diff = min(diff, arr[i] - arr[i - 1])
        return [[arr[i - 1], arr[i]] for i in range(1, n) if arr[i] - arr[i - 1] == diff]

