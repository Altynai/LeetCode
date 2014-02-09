
#include <algorithm>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

int main(int argc, char const *argv[]) {
    int item_count = 10;
    int *array = new int[item_count];
    for (int i = 0; i < item_count; ++i)
        array[i] = item_count - i;
    // std::random_shuffle(array, array + item_count);

    ListNode *head = new ListNode(array[0]);
    ListNode* tail = head;
    for (int i = 1; i < item_count; ++i) {
        ListNode *new_node = new ListNode(array[i]);
        new_node->next = head;
        head = new_node;
    }
    tail->next = head; // make cycle
    
    Solution *solution = new Solution();
    printf("%d\n", solution->hasCycle(head));
    return 0;
}