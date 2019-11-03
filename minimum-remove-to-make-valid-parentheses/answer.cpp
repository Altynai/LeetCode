class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> stk;
        set<int> deleted;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')') {
                if (stk.empty())
                    deleted.insert(i);
                else
                    stk.pop();
            }
        }
        while (!stk.empty()) {
            deleted.insert(stk.top());
            stk.pop();
        }

        int m = n - stk.size();
        char buf[m + 1];
        int p = 0;
        for (int i = 0; i < n; i++) {
            if (deleted.find(i) == deleted.end())
                buf[p++] = s[i];
        }
        buf[p++] = '\0';
        return string(buf, buf + m);
    }
};
