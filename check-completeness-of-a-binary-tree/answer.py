# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCompleteTree(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def dfs(r):
            if not r:
                return 0
            return dfs(r.left) + dfs(r.right) + 1

        n = dfs(root)
        dq = collections.deque()
        dq.append((root, 1))

        while dq:
            (node, i) = dq.popleft()
            if i * 2 <= n and not node.left:
                return False
            elif i * 2 + 1 <= n and not node.right:
                return False

            if i * 2 > n and node.left:
                return False
            elif i * 2 + 1 > n and node.right:
                return False

            if i * 2 <= n:
                dq.append((node.left, i * 2))
            if i * 2 + 1 <= n:
                dq.append((node.right, i * 2 + 1))

        return True

