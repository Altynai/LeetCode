# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isEvenOddTree(self, root: TreeNode) -> bool:
        vals = collections.defaultdict(list)

        def dfs(cur, dep):
            if not cur:
                return
            vals[dep].append(cur.val)
            dfs(cur.left, dep + 1)
            dfs(cur.right, dep + 1)
            
        dfs(root, 0)
        
        for dep, nums in vals.items():
            n = len(nums)
            if any(k % 2 == dep % 2 for k in nums):
                return False

            for i in range(1, n):
                if dep % 2 == 1 and nums[i] >= nums[i - 1]:
                    return False
                if dep % 2 == 0 and nums[i] <= nums[i - 1]:
                    return False

        return True
