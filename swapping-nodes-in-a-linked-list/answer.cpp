/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *swapNodes(ListNode *head, int k) {
    int n = 0;
    for (ListNode *cur = head; cur; cur = cur->next)
      n++;

    ListNode *a = head;
    for (int i = 1; i < k; i++)
      a = a->next;

    ListNode *b = head;
    for (int i = 1; i <= n - k; i++)
      b = b->next;

    swap(a->val, b->val);
    return head;
  }
};
