class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        counter = collections.Counter(text)
        return min(counter.get(ch, 0) // (2 if ch in "lo" else 1) for ch in "balon")

