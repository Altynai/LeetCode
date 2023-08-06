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
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    ListNode *prev = head, *cur = head->next;
    while (cur != nullptr) {
      ListNode *node = new ListNode(gcd(prev->val, cur->val), cur);
      prev->next = node;

      prev = cur;
      cur = cur->next;
    }
    return head;
  }
};
