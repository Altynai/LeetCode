class Solution:
    def getMaxLen(self, a: List[int]) -> int:
        n = len(a)
        ans = 0
        i = 0
        while i < n:
            if a[i] == 0:
                i += 1
                continue

            cnt = 0 
            j = i
            sign = 1
            k1, k2 = -1, -1
            while j < n and a[j] != 0:
                if a[j] < 0:
                    sign *= -1
                    k2 = j
                    if k1 == -1:
                        k1 = j
                cnt += 1
                j += 1

            if sign == 1:
                ans = max(ans, j - i)
            else:
                ans = max(ans, j - i - min(k1 - i + 1, j - k2))

            i = j

        return ans
