class Solution:
    def interpret(self, s: str) -> str:
        return s.replace("(al)", "al").replace("()", "o") 
