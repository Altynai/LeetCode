import string

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        n = len(str(low))
        ans = []
        for i in range(1, 11 - n):
            value = int(string.digits[i:i + n])
            nxt = value % 10 + 1
            while value <= high:
                if low <= value <= high:
                    ans.append(value)
                if nxt >= 10:
                    break
                value = value * 10 + nxt
                nxt += 1
        ans.sort()
        return ans

