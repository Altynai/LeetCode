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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)
            return NULL;
        ListNode* even = head, *odd = head->next, *other_head = head->next;
        while (odd != NULL && odd->next != NULL) {
            ListNode* three = odd->next, *four = odd->next->next;
            even->next = three;
            odd->next = four;
            even = even->next;
            odd = odd->next;
        }
        even->next = other_head;
        return head;
    }
};