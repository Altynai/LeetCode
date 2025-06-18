class Solution:
    def generateTag(self, caption: str) -> str:
        s = list(map(lambda x: x.title(), caption.split()))
        if len(s) > 0:
            s[0] = s[0].lower()
        ans = '#' + ''.join(s)
        return ans[:100]
