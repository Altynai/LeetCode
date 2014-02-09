
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *one = head, *two = head;
        int one_count = 0, two_count = 0;
        while (two != NULL && two->next != NULL) {
            one = one->next;
            one_count += 1;
            two = two->next->next;
            two_count += 2;
            // two pointer meets
            if (one == two)
                break;
        }
        // no cycle
        if (two == NULL || two->next == NULL)
            return NULL;
        // reset one to head, both walk 1 step a time.
        one = head;
        while(one != two){
            one = one->next;
            two = two->next;
        }
        return one;
    }
};