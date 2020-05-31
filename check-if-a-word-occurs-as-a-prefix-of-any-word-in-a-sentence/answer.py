class Solution:
    def isPrefixOfWord(self, sentence: str, searchWord: str) -> int:
        for i, work in enumerate(sentence.split(" "), 1):
            if work.startswith(searchWord):
                return i
        return -1

