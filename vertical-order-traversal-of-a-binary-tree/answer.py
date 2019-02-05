# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def verticalTraversal(self, root: 'TreeNode') -> 'List[List[int]]':
        c = collections.defaultdict(list)
        
        def dfs(root, x, y):
            if not root:
                return
            c[x].append((y, root.val))
            dfs(root.left, x - 1, y + 1)
            dfs(root.right, x + 1, y + 1)
        
        dfs(root, 0, 0)
        ans = []
        mi, mx = min(c), max(c)
        for i in range(mi, mx + 1):
            items = c[i]
            items.sort()
            ans.append([item[1] for item in items])
        return ans

