#include <algorithm>

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        int item_count = listLength(head);
        int *heap_array = new int[item_count];
        ListNode *curr = head;
        for (int i = 0; i < item_count; ++i) {
            heap_array[i] = curr->val;
            curr = curr->next;
        }
        std::make_heap(heap_array, heap_array + item_count);
        std::sort_heap(heap_array, heap_array + item_count);

        curr = head;
        for (int i = 0; i < item_count; ++i) {
            curr->val = heap_array[i];
            curr = curr->next;
        }
        delete [] heap_array;
        return head;
    }

private:
    int listLength(ListNode *head) {
        int item_count = 0;
        while (head != NULL) {
            item_count++;
            head = head->next;
        }
        return item_count;
    }
};
