# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def dfs(self, root, array):
        if root is None:
            return
        if root.left is None and root.right is None:
            array.append(root.val)
            return
        self.dfs(root.left, array)
        self.dfs(root.right, array)

    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        arr1, arr2 = [], []
        self.dfs(root1, arr1)
        self.dfs(root2, arr2)
        return arr1 == arr2

