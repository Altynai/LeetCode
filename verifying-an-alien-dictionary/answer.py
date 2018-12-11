class Solution:
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        w = {ch: i for i, ch in enumerate(order)}
        
        def less(a, b):
            n = min(len(a), len(b))
            for i in range(n):
                if w[a[i]] > w[b[i]]:
                    return False
                elif w[a[i]] < w[b[i]]:
                    return True
            return len(a) <= len(b)
    
        m = len(words)
        for i in range(m):
            for j in range(i):
                if not less(words[j], words[i]):
                    return False
        return True

