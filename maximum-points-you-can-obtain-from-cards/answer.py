def array(a, val=None):
    return [val for _ in range(a)]

def array2d(a, b, val=None):
    return [array(b, val=val) for _ in range(a)]
    
def array3d(a, b, c, val=None):
    return [array2d(b, c, val=val) for _ in range(a)]

def array4d(a, b, c, d, val=None):
    return [array3d(b, c, d, val=val) for _ in range(a)]

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        pfx = array(k + 1, 0)
        for i in range(1, k + 1):
            pfx[i] = pfx[i - 1] + cardPoints[i - 1]

        sfx = array(k + 1, 0)
        for i in range(1, k + 1):
            sfx[i] = sfx[i - 1] + cardPoints[n - i]
        
        return max(pfx[i] + sfx[k - i] for i in range(k + 1))

