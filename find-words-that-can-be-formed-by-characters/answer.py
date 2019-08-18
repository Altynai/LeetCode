from collections import Counter

class Solution:
    def valid(self, w, c):
        w.subtract(c)
        return all(v <= 0 for v in w.values())
        
    def countCharacters(self, words: List[str], chars: str) -> int:
        c = Counter(chars)
        return sum(len(word) for word in words if self.valid(Counter(word), c))

