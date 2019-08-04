# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
        l, r = [0], [0]

        def dfs(cur):
            if not cur:
                return 0
            lc, rc = dfs(cur.left), dfs(cur.right)
            if cur.val == x:
                l[0], r[0] = lc, rc
            return lc + rc + 1
        
        dfs(root)
        blue = max(l[0], r[0], n - l[0] - r[0] - 1)
        red = n - blue - 1
        return blue > red

