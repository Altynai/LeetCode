
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *one = head, *two = head;
        while (two != NULL && two->next != NULL) {
            one = one->next;
            two = two->next->next;
            // two pointer meets
            if (one == two)
                break;
        }
        return two != NULL && two->next != NULL;
    }
};