from collections import defaultdict
from math import inf

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]


class Solution:
    def numSplits(self, s: str) -> int:
        n = len(s)
        cnt = array2d(n + 1, 26, val=0)
        
        for i in range(1, n + 1):
            for j in range(26):
                cnt[i][j] = cnt[i - 1][j]
            cnt[i][ord(s[i - 1]) - ord('a')] += 1
        
        ans = 0
        for i in range(1, n):
            x = sum(1 for j in range(26) if cnt[i][j] > 0)
            y = sum(1 for j in range(26) if cnt[n][j] - cnt[i][j] > 0)
            if x == y:
                ans += 1
        
        return ans

