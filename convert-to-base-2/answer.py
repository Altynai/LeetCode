class Solution:
    def baseNeg2(self, N: int) -> str:
        ans = ""
        while N != 0:
            ans = str(N & 1) + ans
            N = -(N // 2)
        return ans if ans else "0"

