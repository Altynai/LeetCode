class Solution:

    PRIMES = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97]
    MOD = 1_000_000_007
    
    def factorial(self, n):
        ans = 1
        for i in range(1, n + 1):
            ans = (ans * i) % self.MOD
        return ans

    def numPrimeArrangements(self, n: int) -> int:
        m = sum(1 for prime in self.PRIMES if prime <= n)
        return self.factorial(m) * self.factorial(n - m) % self.MOD

