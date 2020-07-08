class Solution:
    def canMakeArithmeticProgression(self, a: List[int]) -> bool:
        a.sort()
        d = a[1] - a[0]
        return all(d == a[i] - a[i - 1] for i in range(2, len(a)))

