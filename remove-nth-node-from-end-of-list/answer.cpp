
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
    int getLength(ListNode *head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    ListNode *removeNthFromStart(ListNode *head, int n) {
        if (n == 1)
            return head->next;
        ListNode *result = head;
        n--;
        while (--n)
            head = head->next;
        head->next = head->next->next;
        return result;
    }

public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        int len = getLength(head);
        if (n > len)
            return head;
        else
            return removeNthFromStart(head, len - n + 1);
    }
};