#include "algorithm"
#include "cstdio"
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        head = doubleRandomList(head);
        return splitRandomList(head);
    }

    void printList(RandomListNode *head) {
        while (head != NULL) {
            printNode(head);
            head = head->next;
        }
    }

    void printNode(RandomListNode *head) {
        printf("%d", head->label);
        if (head->random)
            printf(" %d\n", head->random->label);
        else
            printf(" NULL\n");
    }

private:
    RandomListNode *doubleRandomList(RandomListNode *head) {
        // make L: L0→L1→...→Ln-1→Ln
        // to L': L0→L0→L1→L1→...→Ln→Ln
        RandomListNode *curr = head, *next = NULL, *random = NULL;
        while (curr != NULL) {
            RandomListNode *new_node = new RandomListNode(curr->label);
            next = curr->next;
            new_node->next = next;
            curr->next = new_node;
            curr = next;
        }
        curr = head;
        while (curr != NULL) {
            random = curr->random;
            if (random != NULL)
                curr->next->random = random->next;
            curr = curr->next->next;
        }
        return head;
    }

    RandomListNode *splitRandomList(RandomListNode *head) {
        // make L: L0→L0→L1→L1→...→Ln→Ln
        // to L': L0→L1→...→Ln-1→Ln
        RandomListNode *old_head = head, *new_head = head->next;
        RandomListNode *result = new_head;
        while (new_head->next != NULL) {
            old_head->next = new_head->next;
            new_head->next = old_head->next->next;
            old_head = old_head->next;
            new_head = new_head->next;
        }
        old_head->next = NULL;
        return result;
    }
};

int main(int argc, char const *argv[]) {

    int item_count = 10;
    int *array = new int[item_count];
    for (int i = 0; i < item_count; ++i)
        array[i] = item_count - i;
    // std::random_shuffle(array, array + item_count);

    RandomListNode *head = new RandomListNode(array[0]);
    RandomListNode *tail = head;
    for (int i = 1; i < item_count; ++i) {
        RandomListNode *new_node = new RandomListNode(array[i]);
        new_node->next = head;
        head->random = new_node;
        head = new_node;
    }

    Solution *solution = new Solution();

    solution->printList(head);
    RandomListNode *new_head = solution->copyRandomList(head);
    solution->printList(new_head);
    return 0;
}
