# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):

    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        cnt = 0
        cur = head
        while cur:
            cnt += 1
            cur = cur.next
        for _ in xrange(cnt / 2):
            head = head.next
        return head

