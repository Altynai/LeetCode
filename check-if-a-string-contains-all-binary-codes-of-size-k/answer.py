class Solution:
    def hasAllCodes(self, s: str, k: int) -> bool:
        ans = set()
        n = len(s)
        if k > n:
            return False

        a = 0
        for i in range(k):
            a = a * 2 + int(s[i])
        
        ans.add(a)
        mask = (1 << k) - 1
        for i in range(k, n):
            a = a * 2 + int(s[i])
            a = a & mask
            ans.add(a)
        
        return len(ans) == 2 ** k

