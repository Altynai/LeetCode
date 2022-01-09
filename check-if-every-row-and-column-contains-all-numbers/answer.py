class Solution:
    def checkValid(self, a: List[List[int]]) -> bool:
        n = len(a)
        for i in range(n):
            if len(set(a[i])) != n:
                return False
        for j in range(n):
            if len(set(a[i][j] for i in range(n))) != n:
                return False
        return True
