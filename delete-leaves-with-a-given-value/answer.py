# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def removeLeafNodes(self, root: TreeNode, target: int) -> TreeNode:
        if root is None:
            return None
        if root.left is None and root.right is None:
            return None if root.val == target else root
        root.left = self.removeLeafNodes(root.left, target)
        root.right = self.removeLeafNodes(root.right, target)
        return None if root.left is None and root.right is None and root.val == target else root

