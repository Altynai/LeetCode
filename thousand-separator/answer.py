class Solution:
    def thousandSeparator(self, n: int) -> str:
        ans = []
        s = str(n)
        while len(s) >= 3:
            ans.append(s[-3:])
            s = s[:-3]
        if s:
            ans.append(s)
        ans.reverse()
        return ".".join(ans)

