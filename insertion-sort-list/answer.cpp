
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *new_head = NULL;
        for (ListNode *curr = head; curr != NULL; curr = curr->next)
            new_head = insertListNode(new_head, curr->val);
        return new_head;
    }

private:
    ListNode *insertListNode(ListNode *head, int new_val) {
        // empty list
        if (head == NULL)
            return new ListNode(new_val);
        // one or more items
        ListNode *curr = head, *pre = NULL;
        while (curr != NULL && new_val > curr->val) {
            pre = curr;
            curr = curr->next;
        }
        ListNode* new_node = new ListNode(new_val);
        if (pre != NULL) {
            new_node->next = pre->next;
            pre->next = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        return head;
    }
};
