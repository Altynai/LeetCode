from collections import Counter
from math import comb

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]


class Solution:
    def getProbability(self, balls: List[int]) -> float:
        
        def bitCount(value):
            p = 0
            while value:
                p += 1
                value &= value-1
            return p
            
        tot = 1
        s = sum(balls)
        each = s >> 1
        n = len(balls)
        for i in range(2, s + 1):
            tot *= i
        for ball in balls:
            for i in range(2, ball + 1):
                tot /= i
        
        dp = array3d(each + 1, 1 << n, 1 << n, val=0)
        for i in range(balls[0] + 1):
            x, y = i, balls[0] - i
            if x > each or y > each:
                continue
            mask1 = 1 if x > 0 else 0
            mask2 = 1 if y > 0 else 0
            dp[i][mask1][mask2] += comb(each, x) * comb(each, y)
        
        for i in range(1, n):
            dp2 = array3d(each + 1, 1 << n, 1 << n, val=0)
            
            for cnt in range(each + 1):
                cnt2 = sum(balls[:i]) - cnt
                for mask1 in range(1 << n):
                    for mask2 in range(1 << n):
                        if dp[cnt][mask1][mask2] == 0:
                            continue

                        for j in range(balls[i] + 1):
                            x, y = j, balls[i] - j
                            if x + cnt > each or y + cnt2 > each:
                                continue
                            n_mask1 = (mask1 | (1 << i)) if x > 0 else mask1
                            n_mask2 = (mask2 | (1 << i)) if y > 0 else mask2
                            val = dp[cnt][mask1][mask2] * comb(each - cnt, x) * comb(each - cnt2, y)
                            dp2[cnt + x][n_mask1][n_mask2] += val
            
            dp = dp2

        ans2 = 0
        for mask1 in range(1 << n):
            for mask2 in range(1 << n):
                if bitCount(mask1) == bitCount(mask2):
                    ans2 += dp[each][mask1][mask2]
        
        return ans2 / tot
