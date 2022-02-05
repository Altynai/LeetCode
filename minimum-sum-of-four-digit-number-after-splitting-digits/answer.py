class Solution:
    def minimumSum(self, num: int) -> int:
        s = list(str(num))
        s.sort()

        a = int(s[0] + s[2])
        b = int(s[1] + s[3])
        return a + b
