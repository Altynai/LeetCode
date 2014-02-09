
class Solution {
public:
    void reorderList(ListNode *head) {
        int length = listLength(head);
        if (length <= 1)
            return;
        int right_half = length >> 1;
        int left_half = length - right_half;

        // cut the list
        ListNode *left_list_head = head;
        ListNode *left_list_tail = getListNode(head, left_half - 1);
        ListNode *right_list_head = left_list_tail->next;
        left_list_tail->next = NULL;

        right_list_head = cycleList(right_list_head);
        head = crossTwoLists(left_list_head, right_list_head);
    }

private:
    int listLength(ListNode *head) {
        int length = 0;
        while (head != NULL) {
            length++;
            head = head->next;
        }
        return length;
    }

    ListNode *getListNode(ListNode *head, int index) {
        while (index--)
            head = head->next;
        return head;
    }

    ListNode *cycleList(ListNode *head) {
        // make L: L0→L1→…→Ln-1→Ln
        // to L' : Ln→Ln-1→…→L1→L0
        ListNode *new_head = NULL, *curr = head, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = new_head;
            new_head = curr;
            curr = next;
        }
        return new_head;
    }

    ListNode *crossTwoLists(ListNode *left_head, ListNode *right_head) {
        ListNode *left_curr = left_head, *left_next = NULL;
        ListNode *right_curr = right_head, *right_next = NULL;
        while (right_curr != NULL) {
            left_next = left_curr->next;
            right_next = right_curr->next;

            left_curr->next = right_curr;
            right_curr->next = left_next;

            left_curr = left_next;
            right_curr = right_next;
        }
        return left_head;
    }
};