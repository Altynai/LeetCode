class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        a = []
        for i in range(n):
            s = 0
            for j in range(i, n):
                s += nums[j]
                a.append(s)
        a.sort()
        return sum(a[left - 1:right]) % 1000000007

