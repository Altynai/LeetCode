class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        letters = set(brokenLetters)
        return sum(1 for word in text.split(" ") if set(word) & letters == set())

