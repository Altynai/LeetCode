# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        ls = collections.defaultdict(int)
        
        def dfs(r, level):
            if not r:
                return
            ls[level] += r.val
            dfs(r.left, level + 1)
            dfs(r.right, level + 1)
        
        dfs(root, 1)
        ml, mv = 1, root.val
        for level, value in ls.items():
            if value > mv or (value == mv and level < ml):
                ml, mv = level, value
        return ml

