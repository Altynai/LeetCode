class Solution:
    def decode(self, encoded: List[int]) -> List[int]:
        n = len(encoded) + 1
        first = xor = 0
        for val in encoded:
            xor ^= val
            first ^= xor

        for i in range(1, n + 1):
            first ^= i

        now = first
        ans = [now]
        for i in range(1, n):
            now ^= encoded[i - 1]
            ans.append(now)

        return ans
