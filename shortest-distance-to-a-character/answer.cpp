class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.size();
        vector<int> ans(n, -1);
        int current = 0xffffffff;
        for (int i = 0; i < n; i++) {
            if (S[i] == C) {
                ans[i] = 0;
                current = 0;
            } else {
                if (current != 0xffffffff) {
                    current += 1;
                    if (ans[i] == -1 || current < ans[i])
                        ans[i] = current;
                }
            }
        }
        current = 0xffffffff;
        for (int i = n - 1; i >= 0; i--) {
            if (S[i] == C) {
                ans[i] = 0;
                current = 0;
            } else {
                if (current != 0xffffffff) {
                    current += 1;
                    if (ans[i] == -1 || current < ans[i])
                        ans[i] = current;
                }
            }
        }
        return ans;
    }
};