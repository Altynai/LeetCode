class Solution:
    def maximumWealth(self, accounts: List[List[int]]) -> int:
        return max(sum(r) for r in accounts)

