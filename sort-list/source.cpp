#include <algorithm>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

int main(int argc, char const *argv[]) {
    int item_count = 10;
    int *array = new int[item_count];
    for (int i = 0; i < item_count; ++i)
        array[i] = i;
    std::random_shuffle(array, array + item_count);

    ListNode *head = new ListNode(array[0]);
    for (int i = 1; i < item_count; ++i) {
        ListNode *newNode = new ListNode(array[i]);
        newNode->next = head;
        head = newNode;
    }

    Solution *solution = new Solution();
    head = solution->sortList(head);
    for (ListNode * curr = head; curr != NULL; curr = curr->next)
        printf("%d ", curr->val);
    return 0;
}