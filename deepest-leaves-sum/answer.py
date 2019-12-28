# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        # high, sum
        arr = [0, 0]
        
        def dfs(node, h):
            if not node.left and not node.right:
                if h == arr[0]:
                    arr[1] += node.val
                elif h > arr[0]:
                    arr[0] = h
                    arr[1] = node.val
            
            if node.left:
                dfs(node.left, h + 1)
            if node.right:
                dfs(node.right, h + 1)
        
        dfs(root, 0)
        return arr[1]

