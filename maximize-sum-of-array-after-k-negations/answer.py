class Solution:
    def largestSumAfterKNegations(self, A: List[int], K: int) -> int:
        i, n = 0, len(A)
        A.sort()

        while i < n and K > 0 and A[i] < 0:
            A[i] = -A[i]
            K -= 1
            i += 1

        return sum(A) - 2 * min(A) if K % 2 == 1 else sum(A)

