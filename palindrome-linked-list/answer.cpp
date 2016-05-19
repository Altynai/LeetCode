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
    int length(ListNode* head) {
        int n = 0;
        while (head != NULL) {
            n++;
            head = head->next;
        }
        return n;
    }

public:
    bool isPalindrome(ListNode* head) {
        int n = this->length(head);
        if (n <= 1)
            return true;
        ListNode* cur = head, *nxt = head->next;
        int step = n / 2 - 1;
        for (int i = 0; i < step; ++i) {
            ListNode* nnxt = nxt->next;
            nxt->next = cur;
            cur = nxt;
            nxt = nnxt;
        }
        head->next = NULL;
        if (n % 2 == 1)
            nxt = nxt->next;
        while (cur != NULL && nxt != NULL) {
            if (cur->val != nxt->val)
                return false;
            cur = cur->next;
            nxt = nxt->next;
        }
        return true;
    }
};