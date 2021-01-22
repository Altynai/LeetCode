class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        ans = [first]
        for val in encoded:
            first ^= val
            ans.append(first)
        return ans
