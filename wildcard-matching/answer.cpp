
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *s_back = NULL;
        const char *p_star = NULL;
        while (*s) {
            if (*s == *p || *p == '?')
                s++, p++;
            else if (*p == '*') {
                while (*p == '*')
                    p++;
                if (*p == '\0')
                    return true;
                s_back = s;
                p_star = p;
            } else if (s_back != NULL) {
                s = ++s_back;
                p = p_star;
            } else
                return false;
        }
        while (*p == '*')
            p++;
        return *p == '\0';
    }
};
