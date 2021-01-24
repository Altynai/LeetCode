class Solution:
    def minimumBoxes(self, n: int) -> int:
        l = 1
        r = n 
        ans = -1
        
        while l <= r:
            m = (l + r) // 2
            
            k = int(sqrt(m * 2))
            # flooring: 1, 2, .... , k
            while k * (k + 1) // 2 <= m:
                k += 1
            k -= 1
            rem = m - k * (k + 1) // 2
            
            total = m
            for j in range(k):
                if j + 1 < rem:
                    total += (k - j) * (j + 1)
                else:
                    total += (k - j - 1) * (j + 1)

            if total >= n:
                ans, r = m, m - 1
            else:
                l = m + 1

        return ans
