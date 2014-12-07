
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
    int length(ListNode *node) {
        int num = 0;
        while (node != NULL) {
            num++;
            node = node->next;
        }
        return num;

    }

    ListNode *walkForward(ListNode *node, int step) {
        while (step--) {
            if (node != NULL)
                node = node->next;
        }
        return node;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length_a = length(headA), length_b = length(headB);
        if (length_a >= length_b)
            headA = walkForward(headA, length_a - length_b);
        else
            headB = walkForward(headB, length_b - length_a);

        while (headA != NULL && headB != NULL) {
            if (headA == headB)
                return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};
