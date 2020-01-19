class Solution:
    def maximum69Number (self, num: int) -> int:
        num = list(str(num))
        try:
            num[num.index('6')] = '9'
        except ValueError:
            pass
        return int(''.join(num))

