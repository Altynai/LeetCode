# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isMatch(self, head, root):
        if head.next is None:
            return True
        val = head.next.val
        return (root.left and root.left.val == val and self.isMatch(head.next, root.left)) or \
            (root.right and root.right.val == val and self.isMatch(head.next, root.right))

    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        if not root:
            return False
        if head.val == root.val and self.isMatch(head, root):
            return True
        return self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
