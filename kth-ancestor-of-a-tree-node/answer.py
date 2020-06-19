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

class TreeAncestor:

    def __init__(self, n: int, parent: List[int]):
        dp = array2d(n, 20, val=-1)
        for i in range(n):
            dp[i][0] = parent[i]
        
        for j in range(1, 20):
            for i in range(n):
                k = dp[i][j - 1]
                if k != -1:
                    dp[i][j] = dp[k][j - 1]

        self.n = n
        self.dp = dp

    def getKthAncestor(self, node: int, k: int) -> int:
        for i in range(20):
            if k & (1 << i):
                node = self.dp[node][i]
                if node == -1:
                    return -1
        return node

# Your TreeAncestor object will be instantiated and called as such:
# obj = TreeAncestor(n, parent)
# param_1 = obj.getKthAncestor(node,k)
