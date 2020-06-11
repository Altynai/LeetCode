class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        n = len(arr)
        k = min(k, n)
        m = arr[(n - 1) // 2]
        
        i, j = 0, n - 1
        ans = []
        for _ in range(k):
            di, dj = abs(arr[i] - m), abs(arr[j] - m)
            if dj >= di:
                ans.append(arr[j])
                j -= 1
            else:
                ans.append(arr[i])
                i += 1
        return ans

