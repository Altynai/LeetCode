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
    void deleteNode(ListNode* node) {
        // except the tail
        if (node == NULL || node->next == NULL)
            return;
        while (1) {
            node->val = node->next->val;
            if (node->next->next == NULL) {
                node->next = NULL;
                break;
            }
            node = node->next;
        }
    }
};