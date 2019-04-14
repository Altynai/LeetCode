# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def recoverFromPreorder(self, S: str) -> TreeNode:
        stack = []
        while S:
            # parse
            before = len(S)
            S = S.lstrip('-')
            deep = before - len(S)
            i = S.find('-')
            if i == -1:
                val, S = int(S), ""
            else:
                val, S = int(S[:i]), S[i:]
            node = TreeNode(val)

            # push to stack
            while stack and stack[-1][0] != deep - 1:
                stack = stack[:-1]
            if stack:
                parent = stack[-1][1]
                if parent.left:
                    parent.right = node
                else:
                    parent.left = node
            stack.append((deep, node))
        return stack[0][1]

