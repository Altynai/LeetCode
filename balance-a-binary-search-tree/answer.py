# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nodes = []

        def dfs(u):
            if u is None:
                return
            dfs(u.left)
            nodes.append(u)
            dfs(u.right)

        dfs(root)
        
        def dfs2(nodes, i, j):
            if i > j:
                return None
            k = (i + j) // 2
            u = nodes[k]
            u.left = dfs2(nodes, i, k - 1)
            u.right = dfs2(nodes, k + 1, j)
            return u

        return dfs2(nodes, 0, len(nodes) - 1)

