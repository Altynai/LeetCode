class Solution:
    def getLucky(self, s: str, k: int) -> int:
        t = ""
        for c in s:
            d = ord(c) - ord('a') + 1
            t += str(d)
        
        for i in range(k):
            total = sum(map(int, t))
            t = str(total)
        return int(t)

