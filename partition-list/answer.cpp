
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (!head)
            return head;
        ListNode *lt_head = NULL, *lt_start = NULL;
        ListNode *ge_head = NULL, *ge_start = NULL;
        while (head) {
            if (head->val < x) {
                if (!lt_head) {
                    lt_head = new ListNode(head->val);
                    lt_start = lt_head;
                } else {
                    lt_head->next = new ListNode(head->val);
                    lt_head = lt_head->next;
                }
            } else {
                if (!ge_head) {
                    ge_head = new ListNode(head->val);
                    ge_start = ge_head;
                } else {
                    ge_head->next = new ListNode(head->val);
                    ge_head = ge_head->next;
                }
            }
            head = head->next;
        }
        if (!lt_start)
            return ge_start;
        else {
            lt_head->next = ge_start;
            return lt_start;
        }
    }
};