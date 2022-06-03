class Solution:
    def isPrice(self, s: str) -> bool:
        if s[0] != "$":
            return False
        p = s[1:]
        try:
            float(p)
            return True
        except ValueError:
            return False

    def convertPrice(self, s: str, discount: int) -> str:
        if not self.isPrice(s):
            return s
        price = float(s[1:]) * (100 - discount) / 100.0
        return "${:.2f}".format(price)

    def discountPrices(self, s: str, discount: int) -> str:
        words = s.split(" ")
        n = len(words)
        for i in range(n):
            words[i] = self.convertPrice(words[i], discount)
        return " ".join(words)
