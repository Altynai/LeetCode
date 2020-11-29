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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *na = list1;
    for (int i = 0; i < a - 1; i++)
      na = na->next;

    ListNode *nb = list1;
    for (int i = 0; i <= b; i++)
      nb = nb->next;

    ListNode *x = list2;
    while (x->next != nullptr)
      x = x->next;
    na->next = list2;
    x->next = nb;
    return list1;
  }
};
