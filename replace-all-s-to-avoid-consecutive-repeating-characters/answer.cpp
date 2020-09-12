class Solution {
public:
    string modifyString(string s) {
        string t = s;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (t[i] == '?') {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if ((i > 0 && t[i - 1] == ch) || (i + 1 < n && t[i + 1] == ch))
                        continue;
                    t[i] = ch;
                    break;
                }
            }
        }
        return t;
    }
};
