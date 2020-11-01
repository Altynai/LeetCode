class Solution:
    def canFormArray(self, a: List[int], p: List[List[int]]) -> bool:
        n = len(a)
        m = len(p)
        idx = {b[0]: i for i, b in enumerate(p)}
        
        i = 0
        while i < n:
            j = idx.get(a[i], -1)
            if j == -1:
                return False
            for num in p[j]:
                if a[i] != num:
                    return False
                i += 1
        return True

