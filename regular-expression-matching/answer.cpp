
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0')
            return *s == '\0';
        if (*(p + 1) == '*') {
            while (*s && (*s == *p || *p == '.')) {
                if (isMatch(s, p + 2))
                    return true;
                s++;
            }
            return isMatch(s, p + 2);
        } else
            return (*s == *p || (*s && *p == '.')) && isMatch(++s, ++p);
    }
};
