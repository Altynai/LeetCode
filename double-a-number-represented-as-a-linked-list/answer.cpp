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
  ListNode *doubleIt(ListNode *head) {

    function<int(ListNode *)> dfs = [&](ListNode *cur) -> int {
      if (cur == nullptr)
        return 0;

      cur->val *= 2;
      cur->val += dfs(cur->next);
      int res = cur->val / 10;
      cur->val %= 10;
      return res;
    };

    int res = dfs(head);
    if (res == 1)
      head = new ListNode(1, head);
    return head;
  }
};
