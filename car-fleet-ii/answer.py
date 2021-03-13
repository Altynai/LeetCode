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
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        n = len(cars)
        ans = array(n, -1.0)
        stack = []
        for i in range(n - 1, -1, -1):
            pos, speed = cars[i]
            while stack and (speed <= stack[-1][1] or (stack[-1][0] - pos) / (speed - stack[-1][1]) >= stack[-1][2]):
                stack.pop()
            if not stack:
                stack.append((pos, speed, inf))
            else:
                c = (stack[-1][0] - pos) / (speed - stack[-1][1])
                stack.append((pos, speed, c))
                ans[i] = c
        return ans
