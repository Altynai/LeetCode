# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isUnivalTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        vals = set()
        
        def dfs(node):
            if not node:
                return
            dfs(node.left)
            vals.add(node.val)
            dfs(node.right)
        
        dfs(root)
        return len(vals) == 1

