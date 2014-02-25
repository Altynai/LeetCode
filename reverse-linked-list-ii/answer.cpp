
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *pre = NULL, *result = head;
        int step = n - m + 1;
        while (--m) {
            pre = head;
            head = head->next;
        }
        ListNode *curr = head, *next = NULL, *iter = head;
        head = head->next;
        while (--step) {
            next = head->next;
            head->next = iter;
            iter = head;
            head = next;
        }
        if (pre)
            pre->next = iter;
        else
            result = iter;
        curr->next = head;
        return result;
    }
};