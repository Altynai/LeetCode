from operator import mul, add
from functools import reduce

class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        nums = list(map(int, list(str(n))))
        return reduce(mul, nums) - reduce(add, nums)

