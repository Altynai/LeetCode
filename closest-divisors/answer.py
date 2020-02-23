from math import sqrt

class Solution:
    def closestDivisors(self, num: int) -> List[int]:
        num1, num2, d = num + 1, num + 2, -1
        for i in range(int(sqrt(num1)), 0, -1):
            if num1 % i == 0:
                d = (num1 // i - i)
                ans = [i, num1 // i]
                break
        for i in range(int(sqrt(num2)), 0, -1):
            if num2 % i == 0 and (num2 // i - i) < d:
                d = (num2 // i - i)
                ans = [i, num2 // i]
                break
        return ans

