class Solution(object):
    def maskEmail(self, S):
        S = S.lower()
        name1, part = S.split("@")
        name2, name3 = part.split(".")
        return "{0}*****{1}@{2}.{3}".format(name1[:1], name1[-1:], name2, name3)

    def maskPhone(self, S):
        S = S.replace("(", "")
        S = S.replace(")", "")
        S = S.replace(" ", "")
        S = S.replace("+", "")
        S = S.replace("-", "")
        local = S[-10:]
        country = S[:-10]
        mask = ""
        if country:
            mask = "+{0}-".format("*" * len(country))
        return "{0}***-***-{1}".format(mask, local[-4:])
        
    def maskPII(self, S):
        if "@" in S:
            return self.maskEmail(S)
        return self.maskPhone(S)