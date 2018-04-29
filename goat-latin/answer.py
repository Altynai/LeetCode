class Solution(object):
    def convert(self, index, word):
        first = word[0]
        if first.lower() in "aeiou":
            word += "ma"
        else:
            word = word[1:] + word[:1] + "ma"
        word += "a" * (index + 1)
        return word

    def toGoatLatin(self, S):
        words = S.split()
        for index, word in enumerate(words):
            words[index] = self.convert(index, word)
        return " ".join(words)
