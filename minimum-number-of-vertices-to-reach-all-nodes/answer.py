from collections import Counter

class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        c = Counter((v for (u, v) in edges))
        return [i for i in range(n) if i not in c]

