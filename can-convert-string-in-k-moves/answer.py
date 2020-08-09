from collections import defaultdict

class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s) != len(t):
            return False
        
        n = len(s)
        need = defaultdict(int)
        for i in range(n):
            a = ord(s[i]) - ord('a')
            b = ord(t[i]) - ord('a')
            shift = (b - a + 26) % 26
            if shift > 0:
                need[shift] += 1

        for index, cnt in need.items():
            had = k // 26
            if k % 26 >= index:
                had += 1
            if had < cnt:
                return False
        return True

