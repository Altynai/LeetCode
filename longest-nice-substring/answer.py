class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        n = len(s)
        for k in range(n, 0, -1):
            for i in range(n - k + 1):
                cnt = collections.Counter(s[i:i+k])
                if all((ch.lower() in cnt and ch.upper() in cnt) for ch in cnt.keys()):
                    return s[i:i+k]
        return ""
