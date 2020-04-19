class Solution:
    def reformat(self, s: str) -> str:
        a, b = [], []
        for ch in s:
            if ch.isdigit():
                b.append(ch)
            else:
                a.append(ch)
        
        n, m = len(a), len(b)
        if abs(n - m) > 1:
            return ""

        if n < m:
            n, m = m, n
            a, b = b, a

        ans = []
        for i in range(m):
            ans.append(a[i])
            ans.append(b[i])
        if n > m:
            ans.append(a[-1])
        return "".join(ans)
