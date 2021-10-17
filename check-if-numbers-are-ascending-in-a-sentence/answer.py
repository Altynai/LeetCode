class Solution:
    def areNumbersAscending(self, s: str) -> bool:
        pre = -1
        for token in s.split(" "):
            if token.isdigit():
                val = int(token)
                if val <= pre:
                    return False
                pre = val
        return True
