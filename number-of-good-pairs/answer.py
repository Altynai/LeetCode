class Solution:
    def numIdenticalPairs(self, a: List[int]) -> int:
        n = len(a)
        return sum(1 for i in range(n) for j in range(i + 1, n) if a[i] == a[j])

