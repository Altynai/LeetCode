
class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = 0, last_len = 0;
        for (int i = 0; s[i]; i++) {
            if (s[i] == ' ') {
                if (len)
                    last_len = len;
                len = 0;
            } else
                len += 1;
        }
        if (len)
            last_len = len;
        return last_len;
    }
};