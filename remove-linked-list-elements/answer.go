func removeElements(head *ListNode, val int) *ListNode {
	var answer, previous *ListNode
	answer = nil
	previous = nil
	for head != nil {
		if head.Val != val && answer == nil {
			answer = head
		}
		if head.Val != val {
			previous = head
		} else {
			if previous != nil {
				previous.Next = head.Next
			}
		}
		head = head.Next
	}
	return answer
}