# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, root: TreeNode, cur: int) -> int:
        if not root.left and not root.right:
            return cur
        return (self.dfs(root.left, cur * 2 + root.left.val) if root.left else 0) + \
            (self.dfs(root.right, cur * 2 + root.right.val) if root.right else 0)

    def sumRootToLeaf(self, root: TreeNode) -> int:
        return self.dfs(root, root.val)

