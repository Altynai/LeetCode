class Solution:
    def isCircularSentence(self, s: str) -> bool:
        words = s.split(" ")
        n = len(words)

        for i in range(n):
            if words[i][-1] != words[(i + 1) % n][0]:
                return False
        return True
