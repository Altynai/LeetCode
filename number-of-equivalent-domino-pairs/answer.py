class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        counter = collections.Counter(tuple(sorted(domino)) for domino in dominoes)
        return sum(n * (n - 1) // 2 for n in counter.values())

