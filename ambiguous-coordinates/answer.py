class Solution(object):
    def checkInt(self, s):
        i = int(s)
        return str(i) == s

    def checkFloat(self, s):
        if "." in s:
            t = s.rstrip(".0")
            if s != t:
                return False
            # 001.11
            return self.checkInt(t[:t.find(".")])
        else:
            return self.checkInt(s)
        
    def find(self, s):
        ans = []
        if self.checkInt(s):
            ans.append(s)
        for n in xrange(1, len(s)):
            t = s[:n] + "." + s[n:]
            if self.checkFloat(t):
                ans.append(t)
        return ans
        
    def ambiguousCoordinates(self, S):
        """
        :type S: str
        :rtype: List[str]
        """
        s = S[1:-1]
        ans = []
        for n in xrange(1, len(s)):
            a = self.find(s[:n])
            b = self.find(s[n:])
            if not (a and b):
                continue
            for x in a:
                for y in b:
                    ans.append("({0}, {1})".format(x, y))
        return ans
                
        