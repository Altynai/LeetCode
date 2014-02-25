
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
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        ListNode *new_head = head, *result = head;
        head = head->next;
        while (head) {
            if (new_head->val != head->val) {
                new_head->next = head;
                new_head = head;
            }
            head = head->next;
        }
        new_head->next = head;
        return result;
    }
};