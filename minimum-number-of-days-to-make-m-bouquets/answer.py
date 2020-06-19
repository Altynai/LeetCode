class Solution:
    def minDays(self, b: List[int], m: int, k: int) -> int:
        n = len(b)
        if m * k > n:
            return -1
    
        def search(day):
            cnt = 0
            ans = 0
            for j in range(n):
                if b[j] > day:
                    cnt = 0
                else:
                    cnt += 1
                    if cnt == k:
                        ans += 1
                        cnt = 0
            return ans
    
        l, r = 0, max(b)
        ans = -1
        while l <= r:
            mid = (l + r) >> 1
            if search(mid) >= m:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans

