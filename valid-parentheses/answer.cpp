
class Solution {
private:
    bool match(const char &lh, const char &rh) {
        if (lh == '(')
            return rh == ')';
        if (lh == '{')
            return rh == '}';
        if (lh == '[')
            return rh == ']';
        return false;
    }

public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (stk.size() == 0)
                stk.push(s[i]);
            else {
                if (match(stk.top(), s[i]))
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        return stk.size() == 0;
    }
};