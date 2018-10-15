class Solution {
private:
    bool valid(char c) {
        return islower(c) || isupper(c);
    }

public:
    string reverseOnlyLetters(string S) {
        int n = S.size();
        char* chs = new char[n + 1];
        int i = 0, j = n - 1;
        chs[n] = '\0';
        while (i <= j) {
            if (!valid(S[i])) {
                chs[i] = S[i];
                i++;
            }
            else if (!valid(S[j])) {
                chs[j] = S[j];
                j--;
            }
            else {
                chs[i] = S[j];
                chs[j] = S[i];
                i++;
                j--;
            }
        }
        return string(chs);
    }
};
