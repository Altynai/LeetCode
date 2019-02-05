# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def smallestFromLeaf(self, root: 'TreeNode') -> 'str':
        buf = []
        ans = [None]

        def dfs(root, n):
            try:
                buf[n] = root.val
            except IndexError:
                buf.append(root.val)

            n += 1

            if root.left is None and root.right is None:
                tmp = tuple(buf[n - 1::-1])
                ans[0] = tmp if ans[0] is None or tmp < ans[0] else ans[0]
                return
            
            root.left and dfs(root.left, n)
            root.right and dfs(root.right, n)
        
        dfs(root, 0)
        return "".join(string.ascii_lowercase[i] for i in ans[0])

