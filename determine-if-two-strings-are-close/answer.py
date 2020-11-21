class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        c1 = collections.Counter(word1)
        c2 = collections.Counter(word2)
        
        return sorted(c1.keys()) == sorted(c2.keys()) and \
            sorted(c1.values()) == sorted(c2.values())

