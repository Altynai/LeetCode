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
  int pairSum(ListNode *head) {
    vector<int> a;
    while (head != nullptr) {
      a.push_back(head->val);
      head = head->next;
    }

    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
      ans = max(ans, a[i] + a[n - 1 - i]);
    return ans;
  }
};
