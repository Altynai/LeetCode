from collections import deque
from math import inf

class Solution:
    def findMaxValueOfEquation(self, p: List[List[int]], k: int) -> int:
        dq = deque()
        n = len(p)
        
        x, y = p[0]
        dq.append((x, y - x))
        ans = -inf
        for i in range(1, n):
            xi, yi = p[i]
            while dq and dq[0][0] < xi - k:
                dq.popleft()
            if dq:
                _, delta = dq[0]
                ans = max(ans, xi + yi + delta)
            
            delta = yi - xi
            while dq and delta >= dq[-1][1]:
                dq.pop()
            dq.append((xi, delta))
        
        return ans
        
