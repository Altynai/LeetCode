class Solution:
    def minOperations(self, a: str) -> List[int]:
        n = len(a)
        ans = []
        for i in range(n):
            ans.append(sum(abs(i - j) for j in range(n) if a[j] == "1"))
        return ans

