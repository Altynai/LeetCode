from math import sqrt

class Solution:

    def sumFourDivisors(self, nums: List[int]) -> int:

        def solve(n):
            c, s = 0, 0
            for i in range(1, int(sqrt(n)) + 1):
                if n % i == 0:
                    c += 1 if i * i == n else 2 
                    s += i if i * i == n else i + n // i
            return s if c == 4 else 0

        return sum(solve(num) for num in nums)

