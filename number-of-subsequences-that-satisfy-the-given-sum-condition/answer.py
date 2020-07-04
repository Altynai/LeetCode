class Solution:
    def numSubseq(self, a: List[int], target: int) -> int:
        mod = 10 ** 9 + 7
        n = len(a)

        pow2 = [1 for _ in range(n + 1)]
        for i in range(1, n + 1):
            pow2[i] = (pow2[i - 1] * 2) % mod

        ans = 0
        a.sort()
        i, j = 0, n - 1
        while i <= j:
            while i <= j and a[i] + a[j] > target:
                j -= 1
            if j >= i:
                ans = (ans + pow2[j - i]) % mod
            i += 1
        return ans
