
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL)
            return NULL;
        head = doubleRandomList(head);
        return splitRandomList(head);
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
