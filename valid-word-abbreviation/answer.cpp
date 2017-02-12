class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = 0, m = 0;
        while (m < abbr.size()) {
            // char
            if (abbr[m] >= 'a' && abbr[m] <= 'z') {
                if (n >= word.size() || abbr[m] != word[n])
                    return false;
                m++, n++;
            } else {
                int jump = 0;
                if (m < abbr.size() && abbr[m] == '0')
                    return false;
                while (m < abbr.size() && abbr[m] >= '0' && abbr[m] <= '9') {
                    jump = jump * 10 + abbr[m] - '0';
                    m++;
                }
                n += jump;
            }
        }
        return n == word.size();
    }
};