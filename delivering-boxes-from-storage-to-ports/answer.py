from collections import *
from math import *

def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

class Solution:
    def boxDelivering(self, boxes: List[List[int]], m: int, mc: int, mw: int) -> int:
        n = len(boxes)
        dp = array(n + 1, 0)
        weight = diff = where = 0
        
        def isDifferentPort(index):
            return index + 1 < n and boxes[index][0] != boxes[index + 1][0]

        for i in range(n):

            if i - where == mc:
                weight -= boxes[where][1]
                if isDifferentPort(where):
                    diff -= 1
                where += 1

            assert(i - where + 1 <= mc)
            
            weight += boxes[i][1]
            if i and isDifferentPort(i - 1):
                diff += 1
            
            while weight > mw:
                weight -= boxes[where][1]
                if isDifferentPort(where):
                    diff -= 1
                where += 1

            while where < i and dp[where] == dp[where + 1]:
                weight -= boxes[where][1]
                if isDifferentPort(where):
                    diff -= 1
                where += 1

            dp[i + 1] = dp[where] + diff + 2;

        return dp[n]
