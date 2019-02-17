# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: 'TreeNode', x: 'int', y: 'int') -> 'bool':
        
        def dfs(root, parent, target, depth):
            if not root:
                return None

            if root.val == target:
                return (depth, parent)
            
            ans = dfs(root.left, root, target, depth + 1)
            return dfs(root.right, root, target, depth + 1) if ans is None else ans
        
        xa = dfs(root, None, x, 0)
        ya = dfs(root, None, y, 0)
        return xa[0] == ya[0] and xa[1] != ya[1]

