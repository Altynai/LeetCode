class Solution(object):
    def uniqueMorseRepresentations(self, words):
        morses = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        representations = set()
        for word in words:
            codes = [
                morses[ord(char) - ord("a")]
                for char in word
            ]
            representations.add("".join(codes))
        return len(representations)

