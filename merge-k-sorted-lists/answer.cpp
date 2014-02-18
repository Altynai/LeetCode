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
    ListNode *merge(ListNode *l1, ListNode *l2) {
        if (l1 && !l2)
            return l1;
        if (!l1 && l2)
            return l2;
        if (!l1 && !l2)
            return NULL;

        ListNode *head = NULL;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode *result = head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if (l1)
            head->next = l1;
        else
            head->next = l2;
        return result;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if (n == 0)
            return NULL;
        ListNode *result = NULL;
        for (int i = 0; i < n; i++)
            result = merge(result, lists[i]);
        return result;
    }
};