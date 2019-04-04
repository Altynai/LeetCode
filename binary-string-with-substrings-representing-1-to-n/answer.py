class Solution:
    def queryString(self, S: str, N: int) -> bool:
        for i in range(1, N + 1):
            if "{0:b}".format(i) not in S:
                return False
        return True

