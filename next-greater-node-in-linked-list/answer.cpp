/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        ListNode* cur = head;
        while (cur != nullptr) {
            ans.push_back(cur->val);
            cur = cur->next;
        }
        int n = ans.size();
        deque<int> d = {ans[n - 1]};
        ans[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            int v = ans[i];
            while (!d.empty() && d.front() <= v)
                d.pop_front();
            ans[i] = d.empty() ? 0 : d.front();
            d.push_front(v);
        }
        return ans;
    }
};
