class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size(), result = 0;
        for (int i = 0; i < n; ++i)
            result = result * 26 + (s[i] - 'A') + 1;
        return result;
    }
};
