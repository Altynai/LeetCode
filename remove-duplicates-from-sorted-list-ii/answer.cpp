
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
    void updateNewHead(ListNode *&new_head, ListNode *&result, ListNode *&pre, int count) {
        if (count == 1) {
            if (!new_head) {
                new_head = pre;
                new_head->next = NULL;
                result = pre;
            } else {
                new_head->next = pre;
                new_head = pre;
                new_head->next = NULL;
            }
        }
    }

public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head)
            return head;
        ListNode *new_head = NULL, *result = NULL;
        int count = 1;
        ListNode *curr = head->next, *pre = head;
        while (curr) {
            if (curr->val == pre->val) {
                count += 1;
            } else {
                updateNewHead(new_head, result, pre, count);
                count = 1;
            }
            pre = curr;
            curr = curr->next;
        }
        updateNewHead(new_head, result, pre, count);
        return result;
    }
};