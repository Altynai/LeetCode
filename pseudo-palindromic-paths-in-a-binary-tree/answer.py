# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pseudoPalindromicPaths (self, root: TreeNode) -> int:
        cnt = [0 for i in range(9)]
        ans = [0]

        def dfs(r):
            cnt[r.val - 1] += 1
            
            if r.left is None and r.right is None:
                odd = sum(1 for i in range(9) if cnt[i] % 2 == 1)
                if odd <= 1:
                    ans[0] += 1
                cnt[r.val - 1] -= 1
                return

            if r.left:
                dfs(r.left)
            if r.right:
                dfs(r.right)
            cnt[r.val - 1] -= 1
        
        dfs(root)
        return ans[0]

