
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
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        int length = lengthOfList(head);
        if (length == 0 || k == 1 || k > length)
            return head;
        ListNode *start = head, *current = head, *tail_next = NULL, *result = NULL, *pre_tail = NULL, *tail = NULL;
        for (int i = 0; i < length / k; i++) {
            tail = start;
            for (int j = 0; j < k - 1; j++)
                tail = tail->next;
            if (i == 0)
                result = tail;
            tail_next = tail->next;

            ListNode *temp_head = start;
            current = start->next;
            start->next = tail_next;
            for (int j = 0; j < k - 1; j++) {
                ListNode *current_next = current->next;
                current->next = start;
                start = current;
                current = current_next;
            }
            if (pre_tail)
                pre_tail->next = start;
            pre_tail = temp_head;
            pre_tail->next = current;
            start = tail_next;
        }
        return result;
    }
};