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
  ListNode *removeNodes(ListNode *head) {
    vector<int> a;
    for (ListNode *p = head; p; p = p->next)
      a.push_back(p->val);

    int n = a.size();
    ListNode *last = new ListNode(a[n - 1]);
    ListNode *ans = last, *nxt = last;

    for (int i = n - 2, ma = a[n - 1]; i >= 0; i--) {
      if (ma <= a[i]) {
        ans = new ListNode(a[i], nxt);
        nxt = ans;
      }
      ma = max(a[i], ma);
    }
    return ans;
  }
};
