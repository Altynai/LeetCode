
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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *result = head->next, *pre = NULL, *one, *two, *three;
        while (head && head->next) {
            one = head;
            two = head->next;
            three = head->next->next;
            if (pre)
                pre->next = two;
            two->next = one;
            one->next = three;
            head = three;
            pre = one;
        }
        return result;
    }
};