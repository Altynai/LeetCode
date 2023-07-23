class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []
        for word in words:
            ans.extend(word.split(separator))
        return [s for s in ans if s]
