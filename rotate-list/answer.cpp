
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
    int lengthOfList(ListNode *head) {
        int len = 0;
        while (head) {
            len += 1;
            head = head->next;
        }
        return len;
    }

public:
    ListNode *rotateRight(ListNode *head, int k) {
        int len = lengthOfList(head);
        if (len == 0)
        	return head;
        k = k % len; // trick
        if (k == 0)
            return head;
        int index = len - k - 1;
        ListNode *tail = head, *result = NULL;
        while (index--)
            tail = tail->next;
        // cut the list
        result = tail->next;
        tail->next = NULL;
        tail = result;
        while (tail->next)
            tail = tail->next;
        tail->next = head;
        return result;
    }
};