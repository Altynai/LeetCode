/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    void addTwoNumbers(ListNode *head, ListNode *l1, ListNode *l2) {
        int more = 0;
        while (1) {
            if (l1 != NULL) {
                head->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                head->val += l2->val;
                l2 = l2->next;
            }
            if (head->val >= 10)
                head->next = new ListNode(head->val / 10);
            head->val %= 10;
            if (l1 == NULL && l2 == NULL)
                break;
            if (head->next == NULL)
                head->next = new ListNode(0);
            head = head->next;
        }
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        addTwoNumbers(head, l1, l2);
        return head;
    }
};