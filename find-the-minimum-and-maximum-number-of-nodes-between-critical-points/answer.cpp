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
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    int i = 0, first = -1, lastPos = -1, mi = INT_MAX;
    for (ListNode *cur = head, *pre = nullptr; cur->next;
         i++, pre = cur, cur = cur->next) {
      int val = cur->val;
      if (pre && ((pre->val < val && val > cur->next->val) ||
                  (pre->val > val && val < cur->next->val))) {
        if (first == -1)
          first = i;
        if (lastPos != -1)
          mi = min(i - lastPos, mi);
        lastPos = i;
      }
    }
    if (mi == INT_MAX)
      return {-1, -1};
    return {mi, lastPos - first};
  }
};
