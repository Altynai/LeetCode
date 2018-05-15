class Solution {
private:
    string s;
    int n;

    void init(const string& s) {
        this->s = s;
        n = s.size();
    }

    string dfs(int i, int j) {
        string ans = "";
        for (int k = i; k < j; ) {
            if (isdigit(s[k])) {
                int count = 0;
                while (k < j && isdigit(s[k])) {
                    count = count * 10 + s[k] - '0';
                    k++;
                }
                stack<char> stk;
                stk.push(s[k++]);  // '['
                int start = k;
                while (k < j && !stk.empty()) {
                    if (s[k] == '[')
                        stk.push(s[k]);
                    else if (s[k] == ']')
                        stk.pop();
                    k++;
                }
                int end = k - 1;
                string sub = dfs(start, end);
                while (count--)
                    ans = ans + sub;
            } else {
                ans += s[k];
                k++;
            }
        }
        return ans;
    }

public:
    string decodeString(string s) {
        init(s);
        return dfs(0, n);
    }
};
