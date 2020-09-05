class Solution:
    def containsPattern(self, a: List[int], m: int, k: int) -> bool:
        n = len(a)
        if m * k > n:
            return False
        
        for i in range(n - m + 1):
            j = i + m
            cnt = 1
            while j + m - 1 < n and all(a[i + x] == a[j + x] for x in range(m)):
                cnt += 1
                if cnt >= k:
                    return True
                j += m

        return False
