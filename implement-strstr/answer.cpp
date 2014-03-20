
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int n = strlen(haystack), m = strlen(needle);
        int result = kmp(haystack, needle, n, m);
        if (result == -1)
            return NULL;
        else
            return haystack + result;
    }

private:
    void getnext(char *s, int *next) {
        next[0] = -1;
        for (int i = 0, j = -1; s[i]; i++, j++) {
            while (j != -1 && s[i] != s[j]) {
                j = next[j];
            }
            next[i + 1] = j + 1;
        }
    }

    int kmp(char *s1, char *s2, int n, int m) {
        if (m == 0)
            return 0;
        int *next = new int[m + 1];
        getnext(s2, next);
        for (int i = 0, j = 0; i < n; i++, j++) {
            while (j != -1 && s1[i] != s2[j]) {
                j = next[j];
            }
            if (j >= m - 1) {
                return i + 1 - m;
            }
        }
        return -1;
    }
};