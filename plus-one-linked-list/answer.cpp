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
    int dfs(ListNode* node) {
        if (node == NULL)
            return 0;
        // tail node
        else if (node->next == NULL) {
            node->val++;
            if (node->val > 9) {
                node->val = 0;
                return 1;
            }
            return 0;
        } else {
            int base = dfs(node->next);
            node->val += base;
            if (node->val > 9) {
                node->val = 0;
                return 1;
            }
            return 0;
        }
    }

    ListNode* plusOne(ListNode* head) {
        int base = dfs(head);
        if (base > 0) {
            ListNode* changed = new ListNode(1);
            changed->next = head;
            return changed;
        }
        return head;
    }
};