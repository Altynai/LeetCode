
class Solution {
private:
    bool match(const char &a, const char &b) {
        return a == '(' && b == ')';
    }

public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (stk.size() == 0)
                stk.push(i);
            else if (match(s[stk.top()], s[i]))
                stk.pop();
            else
                stk.push(i);
        }
        // whole `s` is valid
        if (stk.size() == 0)
            return n;
        int end = n, start, result = 0;
        while (!stk.empty()) {
            start = stk.top();
            stk.pop();
            result = std::max(result, end - start - 1);
            end = start;
        }
        if (end)
            result = std::max(result, end);
        return result;
    }
};