class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> stk;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == ')' && !stk.empty() && stk.top() == '(')
                stk.pop();
            else
                stk.push(S[i]);
        }
        return stk.size();
    }
};
