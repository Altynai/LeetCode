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
  ListNode *mergeNodes(ListNode *head) {
    if (head->next == nullptr)
      return nullptr;
    head = head->next;
    int sum = 0;
    while (head->val > 0) {
      sum += head->val;
      head = head->next;
    }
    return new ListNode(sum, mergeNodes(head));
  }
};
