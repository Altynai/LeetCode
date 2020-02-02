# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        mod = 1000000000 + 7

        def cal(a, b):
            c, d = (a // mod) + (b // mod), (a % mod) * (b % mod)
            return (c + d // mod, d % mod)

        def getSum(r):
            return r.val + getSum(r.left) + getSum(r.right) if r else 0

        total = getSum(root)
        ans = [(0, 0)]

        def findMax(r):
            if not r:
                return 0
            a = r.val + findMax(r.left) + findMax(r.right)
            b = total - a
            ans[0] = max(ans[0], cal(a, b))
            return a
        
        findMax(root)
        return ans[0][1]

