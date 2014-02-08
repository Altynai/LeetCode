#include <algorithm>
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode *new_head = NULL;
        for (ListNode *curr = head; curr != NULL; curr = curr->next)
            new_head = insertListNode(new_head, curr->val);
        return new_head;
    }

    void printList(ListNode *head) {
        for (ListNode *curr = head; curr != NULL; curr = curr->next)
            printf("%d ", curr->val);
        printf("\n");
    }

    void printListNode(ListNode *head) {
        if(head == NULL)
            printf("NULL ");
        else
            printf("%d ", head->val);
    }

private:
    ListNode *insertListNode(ListNode *head, int new_val) {
        // empty list
        if (head == NULL)
            return new ListNode(new_val);
        // one or more items
        ListNode *curr = head, *pre = NULL;
        while (curr != NULL && new_val > curr->val) {
            pre = curr;
            curr = curr->next;
        }
        ListNode* new_node = new ListNode(new_val);
        if (pre != NULL) {
            new_node->next = pre->next;
            pre->next = new_node;
        } else {
            new_node->next = head;
            head = new_node;
        }
        return head;
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
        ListNode *new_node = new ListNode(array[i]);
        new_node->next = head;
        head = new_node;
    }

    Solution *solution = new Solution();
    head = solution->insertionSortList(head);
    solution->printList(head);
    return 0;
}