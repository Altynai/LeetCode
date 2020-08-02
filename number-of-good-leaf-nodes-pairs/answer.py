# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

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
    def countPairs(self, r: TreeNode, d: int) -> int:

        ans = [0]

        def dfs(root):
            if not root.left and not root.right:
                return {0: 1}
            
            l = dfs(root.left) if root.left else dict()
            r = dfs(root.right) if root.right else dict()
            
            l = {k + 1: v for k, v in l.items() if k <= d}
            r = {k + 1: v for k, v in r.items() if k <= d}
            
            for dl, cl in l.items():
                for i in range(1, d - dl + 1):
                    ans[0] += cl * r.get(i, 0)
            
            keys = set(l.keys()) | set(r.keys())
            return {k: l.get(k, 0) + r.get(k, 0) for k in keys}

        dfs(r)
        return ans[0]

