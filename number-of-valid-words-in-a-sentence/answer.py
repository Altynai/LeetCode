class Solution:
    def countValidWords(self, s: str) -> int:
        def isValid(token):
            if not token:
                return 0

            if any(ch.isdigit() for ch in token):
                return 0

            cnt = token.count("-")
            if cnt >= 2:
                return 0
            elif cnt == 1:
                a, b = token.split("-")
                if not (a and a[-1].islower() and b and b[0].islower()):
                    return 0

            cnt = sum(token.count(mark) for mark in "!.,")
            if cnt >= 2:
                return 0
            elif cnt == 1 and token[-1] not in "!.,":
                return 0
            return 1

        return sum(isValid(token) for token in s.split(" "))
