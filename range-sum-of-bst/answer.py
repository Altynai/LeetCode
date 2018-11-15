# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    def rangeSumBST(self, root, L, R):
        """
        :type root: TreeNode
        :type L: int
        :type R: int
        :rtype: int
        """
        self.ans = 0
        
        def dfs(root):
            if not root:
                return
            if L <= root.val <= R:
                self.ans += root.val

            if root.val > L:
                dfs(root.left)
            if root.val < R:
                dfs(root.right)
        
        dfs(root)
        return self.ans

