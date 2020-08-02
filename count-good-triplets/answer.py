class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n = len(arr)
        
        def valid(i, j, w):
            return abs(arr[i] - arr[j]) <= w

        ans = 0
        for i in range(n):
            for j in range(i + 1, n):
                if valid(i, j, a):
                    for k in range(j + 1, n):
                        if valid(j, k, b) and valid(i, k, c):
                            ans += 1
        return ans

