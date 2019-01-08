class Solution:
    
    def split(self, s):
        i, nr, r = "", "", ""

        p = s.find('(')
        if p != -1:
            r = s[p + 1:-1]
            s = s[:p]

        s = s.rstrip('.')
        p = s.find('.')
        if p != -1:
            nr = s[p + 1:]
            s = s[:p]
        i = s
        return (i, nr, r)
        
    def gcd(self, a, b):
        if a < b:
            a, b = b, a
        while b > 0:
            a, b = b, a % b
        return a

    def trans(self, s):
        i, nr, r = s
        a, b = int(i), 1

        for c in nr:
            a = a * 10 + int(c)
            b *= 10
        
        # x = a.r
        # 10^n * x = ar.r
        # (10^n - 1) * x = ar - a
        if r:
            tp = 10 ** len(r)
            b *= (tp - 1)
            a = a * tp + int(r) - a
        
        c = self.gcd(a, b)
        return (a / c, b / c)

    def isRationalEqual(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        s, t = self.split(S), self.split(T)
        return self.trans(s) == self.trans(t)

