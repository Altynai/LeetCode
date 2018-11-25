#define FOR(i, s, t) for (int i = (s); i < (t); i++)

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size(), j = 0;
        stack<int> s;
        FOR(i, 0, n) {
            s.push(pushed[i]);
            while (j < n && s.size() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        return s.size() == 0;
    }
};
