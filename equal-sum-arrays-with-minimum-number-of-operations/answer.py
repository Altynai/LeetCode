from collections import *
from math import *
from heapq import *

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

dx = (0, 1, -1, 0)
dy = (1, 0, 0, -1)

class Solution:
    def minOperations(self, a: List[int], b: List[int]) -> int:
        n = len(a)
        m = len(b)
        
        if n > m * 6 or m > n * 6:
            return -1
    
        A = array(7, 0)
        B = array(7, 0)
        sa = sb = 0
        for num in a:
            A[num] += 1
            sa += num
        for num in b:
            B[num] += 1
            sb += num

        l = max(n, m)
        r = min(n, m) * 6
        ans = n + m
        for s in range(l, r + 1):
            cnt = 0
            if sa > s:
                left = sa - s
                for i in range(6, 1, -1):
                    # offer A[i] * (i - 1)
                    need = (left + i - 2) // (i - 1)
                    if A[i] >= need:
                        cnt += need
                        break
                    else:
                        cnt += A[i]
                        left -= A[i] * (i - 1)
                    
            elif sa < s:
                left = s - sa
                for i in range(1, 6):
                    # offer A[i] * (6 - i)
                    need = (left + 5 - i) // (6 - i)
                    if A[i] >= need:
                        cnt += need
                        break
                    else:
                        cnt += A[i]
                        left -= A[i] * (6 - i)
            
            if sb > s:
                left = sb - s
                for i in range(6, 1, -1):
                    # offer B[i] * (i - 1)
                    need = (left + i - 2) // (i - 1)
                    if B[i] >= need:
                        cnt += need
                        break
                    else:
                        cnt += B[i]
                        left -= B[i] * (i - 1)
                    
            elif sb < s:
                left = s - sb
                for i in range(1, 6):
                    # offer B[i] * (6 - i)
                    need = (left + 5 - i) // (6 - i)
                    if B[i] >= need:
                        cnt += need
                        break
                    else:
                        cnt += B[i]
                        left -= B[i] * (6 - i)
            
            ans = min(ans, cnt)
        return ans
            
