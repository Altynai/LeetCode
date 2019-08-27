# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeZeroSumSublists(self, head: ListNode) -> ListNode:
        stack = collections.deque()
        stack.append((None, 0))
        seen = collections.defaultdict(collections.deque)
        seen[0].append(0)

        cur = head
        while cur:
            sum = stack[-1][1] + cur.val
            stack.append((cur, sum))
            seen[sum].append(len(stack) - 1)

            dq = seen[sum]
            if len(dq) == 2:
                first_pointer = dq[0]
                while len(stack) - 1 > first_pointer:
                    _, sum2 = stack.pop()
                    seen[sum2].pop()

            cur = cur.next
        
        if len(stack) == 1:
            return None

        stack.popleft()
        head, _ = stack.popleft()
        pre = head
        while stack:
            node, _ = stack.popleft()
            pre.next = node
            pre = node
        pre.next = None
        return head

