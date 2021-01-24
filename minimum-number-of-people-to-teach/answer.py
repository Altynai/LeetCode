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
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        m = len(languages)
        languages = list(map(set, languages))
        
        good = array2d(m, m, 0)
        for (u, v) in friendships:
            u -= 1
            v -= 1
            if languages[u] & languages[v]:
                good[u][v] = good[v][u] = 1
        
        ans = m
        for lang in range(1, n + 1):
            teach = set()
            for (u, v) in friendships:
                u -= 1
                v -= 1
                if not good[u][v]:
                    if lang not in languages[u]:
                        teach.add(u)
                    if lang not in languages[v]:
                        teach.add(v)
            ans = min(ans, len(teach))

        return ans
                
