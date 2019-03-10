class Solution:
    def clumsy(self, N: int) -> int:
        
        def f(n):
            if n >= 4:
                return n * (n - 1) // (n - 2), n - 3
            elif n == 3:
                return n * (n - 1) // (n - 2), 0
            elif n == 2:
                return n * (n - 1), 0
            else:
                return n, 0
        
        ans = sum(f(N))
        N -= 4
        while N >= 0:
            a, b = f(N)
            ans = ans - a + b
            N -= 4
        return ans

