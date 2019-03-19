class Solution:
    def bitwiseComplement(self, N: int) -> int:
        s = bin(N)[2:]
        t = ''.join(['1' if ch == '0' else '0' for ch in s])
        return int(t, 2)

