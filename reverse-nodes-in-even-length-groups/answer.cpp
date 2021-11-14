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
  ListNode *reverseEvenLengthGroups(ListNode *head) {
    vector<vector<int>> groups;

    ListNode *cur = head;
    for (int cnt = 1; cur != nullptr; cnt++) {
      vector<int> group;
      for (int i = 0; i < cnt && cur != nullptr; i++, cur = cur->next)
        group.push_back(cur->val);
      groups.push_back(group);
    }

    cur = head;
    int n = groups.size();
    for (int i = 0; i < n; i++) {
      int m = groups[i].size();
      if (m & 1) {
        for (int j = 0; j < m; j++, cur = cur->next)
          cur->val = groups[i][j];
      } else {
        for (int j = m - 1; j >= 0; j--, cur = cur->next)
          cur->val = groups[i][j];
      }
    }
    return head;
  }
};
