"""
   This is the custom function interface.
   You should not implement it, or speculate about its implementation
   class CustomFunction:
       # Returns f(x, y) for any given positive integers x and y.
       # Note that f(x, y) is increasing with respect to both x and y.
       # i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
       def f(self, x, y):
  
"""
class Solution:
    def bs(self, customfunction, x, z):
        l, r = 1, 1000
        while l <= r:
            y = (l + r) >> 1
            p = customfunction.f(x, y)
            if p == z:
                return y
            elif p < z:
                l = y + 1
            else:
                r = y - 1
        return None

    def findSolution(self, customfunction: 'CustomFunction', z: int) -> List[List[int]]:
        ans = []
        for x in range(1, 1001):
            y = self.bs(customfunction, x, z)
            if y is not None:
                ans.append([x, y])
        return ans

