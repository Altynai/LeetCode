class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        c = collections.Counter(A[0])
        for i in range(1, len(A)):
            c &= collections.Counter(A[i])
        return list(c.elements())

