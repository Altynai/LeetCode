class Solution:
    def maxDistance(self, a: List[int], m: int) -> int:
        a.sort()
        n = len(a)
        
        def check(gap):
            cnt = 0
            pre = -gap
            for i in range(n):
                if a[i] - gap >= pre:
                    pre = a[i]
                    cnt += 1
            return cnt >= m
            
        l, r = 1, a[-1] - a[0]
        ans = -1
        while l <= r:
            mid = (l + r) >> 1
            if check(mid):
                ans = mid
                l = mid + 1
            else:
                r = mid - 1
        return ans
