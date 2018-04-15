/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    set<int> st;

public:
    int numComponents(ListNode* head, vector<int>& G) {
        st.clear();
        for (auto num : G)
            st.insert(num);
        int count = 0, components = 0;
        while (head != NULL) {
            if (st.find(head->val) != st.end()) {
                count++;
            } else {
                if (count)
                    components++;
                count = 0;
            }
            head = head->next;
        }
        if (count)
            components++;
        return components;
    }
};