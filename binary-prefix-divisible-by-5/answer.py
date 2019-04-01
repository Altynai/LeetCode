class Solution:
    def prefixesDivBy5(self, A: List[int]) -> List[bool]:
        ans, cur = [], 0
        for a in A:
            cur = cur * 2 + a
            ans.append(cur % 5 == 0)
            cur = cur % 5
        return ans

