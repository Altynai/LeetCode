class Solution {
public:
    string makeGood(string a) {
        int n = a.size();
        char s[n + 1];
        int m = 0;
        for (char ch: a) {
            s[m++] = ch;
            if (m >= 2 && abs(s[m - 1] - s[m - 2]) == 32)
                m -= 2;
        }
        return string(s, s + m);
    }
};
