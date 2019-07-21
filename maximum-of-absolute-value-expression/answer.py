class Solution:

    def iter(self, arr1, arr2, op):
        for idx, (a, b) in enumerate(zip(arr1, arr2)):
            c = a + b if op & 2 else a - b
            yield c + idx if op & 1 else c - idx

    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        # "+ a[i] - a[j] + b[i] - b[j] + i - j" --> "(a[i] + b[i] + i) - (a[j] + b[j] + j)"  -->  A
        # "+ a[i] - a[j] + b[i] - b[j] - i + j" --> "(a[i] + b[i] - i) - (a[j] + b[j] - j)"  -->  B
        # "+ a[i] - a[j] - b[i] + b[j] + i - j" --> "(a[i] - b[i] + i) - (a[j] - b[j] + j)"  -->  C
        # "+ a[i] - a[j] - b[i] + b[j] - i + j" --> "(a[i] - b[i] - i) - (a[j] - b[j] - j)"  -->  D
        # "- a[i] + a[j] + b[i] - b[j] + i - j" --> "-(a[i] - b[i] - i) + (a[j] - b[j] - j)"  -->  D
        # "- a[i] + a[j] + b[i] - b[j] - i + j" --> "-(a[i] - b[i] + i) + (a[j] - b[j] + j)"  -->  C
        # "- a[i] + a[j] - b[i] + b[j] + i - j" --> "-(a[i] + b[i] - i) + (a[j] + b[j] - j)"  -->  B
        # "- a[i] + a[j] - b[i] + b[j] - i + j" --> "-(a[i] + b[i] + i) + (a[j] + b[j] + j)"  -->  A
        return max(max(self.iter(arr1, arr2, op)) - min(self.iter(arr1, arr2, op)) for op in range(4))

