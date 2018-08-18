# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deleteNode(self, root, key):
        """
        :type root: TreeNode
        :type key: int
        :rtype: TreeNode
        """
        if not root:
            return None
        elif root.val != key:
            root.left = self.deleteNode(root.left, key)
            root.right = self.deleteNode(root.right, key)
            return root
        
        if not root.left and not root.right:
            return None
        elif root.left and not root.right:
            return root.left
        elif not root.left and root.right:
            return root.right
        else:
            cur = root.right
            while cur.left:
                cur = cur.left
            root.val = cur.val
            root.right = self.deleteNode(root.right, cur.val)
            return root
