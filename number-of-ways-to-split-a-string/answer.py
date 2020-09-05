class Solution:
    def numWays(self, s: str) -> int:
        n = len(s)
        mod = 1000000000 + 7
        m = s.count('1')
        if m % 3 != 0:
            return 0
        elif m == 0:
            return (n - 1) * (n - 2) // 2 % mod

        def countZero(num):
            a = 0
            cnt = 0
            for i in range(n):
                if s[i] == '1':
                    cnt += 1
                    if cnt == num:
                        i += 1
                        while i < n and s[i] == '0':
                            a += 1
                            i += 1
                        return a
            return -1
            
        return (countZero(m // 3) + 1) * (countZero(m // 3 * 2) + 1) % mod

