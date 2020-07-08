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
    def numSubmat(self, a: List[List[int]]) -> int:
        n, m = len(a), len(a[0])
        ans = 0
        col = array2d(m + 1, n + 1, 0)
        
        for j in range(1, m + 1):
            col[j][0] = 0
            for i in range(1, n + 1):
                val = a[i - 1][j - 1]
                col[j][i] = col[j][i - 1] + val

        for i in range(1, n + 1):
            for j in range(i, n + 1):
                # i -> j
                p = []
                for k in range(1, m + 1):
                    if col[k][j] - col[k][i - 1] == j - i + 1:
                        p.append(1)
                    else:
                        p.append(0)

                pre = p[0]
                cnt = 0
                for k in range(m):
                    if p[k] == pre:
                        cnt += 1
                    else:
                        if pre == 1:
                            ans += (cnt * (cnt - 1) // 2)
                            ans += cnt
                        cnt = 1
                        pre = p[k]
                
                if pre == 1 and cnt > 0:
                    ans += (cnt * (cnt - 1) // 2)
                    ans += cnt
        
        return ans

