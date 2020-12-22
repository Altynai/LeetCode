class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        a = set(allowed)
        return sum(1 for b in words if set(b) & a == set(b))
