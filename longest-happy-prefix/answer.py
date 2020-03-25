class KMP(object):
    
    def __init__(self, pattern):
        self.pattern = pattern

        m = len(pattern)
        # longest prefix suffix: `lps[i] = k` indicates pattern[0:k] == pattern[i - k + 1:i + 1]
        lps = [0] * m
        i, j = 1, 0
        while i < m:
            if pattern[i] == pattern[j]:
                lps[i] = j + 1
                i += 1
                j += 1
            else:
                if j == 0:
                    lps[i] = 0
                    i += 1
                else:
                    j = lps[j - 1]
        self.lps = lps
    
    def search(self, text):
        # returns index
        n = len(text)
        i, j = 0, 0
        print(self.lps)
        while i < n:
            if text[i] == self.pattern[j]:
                i += 1
                j += 1
            else:
                if j == 0:
                    i += 1
                else:
                    j = self.lps[j - 1]
            # found
            if j == len(self.pattern):
                return i - len(self.pattern)
        return -1


class Solution:
    def longestPrefix(self, s: str) -> str:
        n = KMP(s).lps[-1]
        return s[:n]

