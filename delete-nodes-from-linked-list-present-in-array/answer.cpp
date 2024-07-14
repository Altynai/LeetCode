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
  ListNode *modifiedList(vector<int> &a, ListNode *head) {
    unordered_set<int> s(a.begin(), a.end());
    ListNode *now = nullptr, *ans = nullptr;
    for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
      int val = cur->val;
      if (s.count(val))
        continue;
      if (now == nullptr) {
        ans = now = new ListNode(val);
      } else {
        now->next = new ListNode(val);
        now = now->next;
      }
    }
    return ans;
  }
};
