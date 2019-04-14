class Solution:
    def longestArithSeqLength(self, A: List[int]) -> int:
        best = collections.defaultdict(int)
        n, ans = len(A), 0
        for j in range(1, n):
            for i in range(0, j):
                d = A[j] - A[i]
                best[(j, d)] = max(best[(j, d)], 1 + best[(i, d)])
                ans = max(ans, best[(j, d)])
        return ans + 1

