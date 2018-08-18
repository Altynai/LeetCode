
class Node:
    def __init__(self):
        self.children = {}
        self.isWord = False

class Solution:

    def insert(self, word):
        root = self.root
        for ch in word:
            if ch not in root.children:
                root.children[ch] = Node()
            root = root.children[ch]
        root.isWord = True
    
    def cut(self, word):
        root = self.root
        for i, ch in enumerate(word):
            if ch not in root.children:
                return word
            root = root.children[ch]
            if root.isWord:
                return word[:i + 1]
        return word

    def replaceWords(self, dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        self.root = Node()
        for word in dict:
            self.insert(word)
        return " ".join(map(self.cut, sentence.split(" ")))

