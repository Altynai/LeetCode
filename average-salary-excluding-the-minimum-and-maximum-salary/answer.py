class Solution:
    def average(self, a: List[int]) -> float:
        a.sort()
        a = a[1:-1]
        return sum(a) / len(a)

