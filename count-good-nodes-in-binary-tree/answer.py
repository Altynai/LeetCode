# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        
        ans = [0]

        def dfs(r, val):
            if not r:
                return
            if val <= r.val:
                ans[0] += 1
            dfs(r.left, max(val, r.val))
            dfs(r.right, max(val, r.val))
        
        dfs(root, root.val)
        return ans[0]
