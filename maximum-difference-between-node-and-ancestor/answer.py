# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def dfs(self, root: TreeNode):
        val = root.val
        if not root.left and not root.right:
            return (val, val, 0)

        mn = mx = val
        ans = 0
        for node in filter(None, (root.left, root.right)):
            r = self.dfs(node)
            mn, mx, ans = min(mn, r[0]), max(mx, r[1]), max(ans, r[2], abs(val - r[0]), abs(val - r[1]))
        return (mn, mx, ans)

    def maxAncestorDiff(self, root: TreeNode) -> int:
        return self.dfs(root)[2]

