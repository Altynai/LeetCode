class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        return [
            word for word in words
            if any(other.find(word) != -1 for other in words if other != word)
        ]

