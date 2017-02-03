#include <ctype.h>

class Solution {
private:
    string removeDash(string& S) {
        int n = S.length();
        if (n == 0)
            return "";
        vector<char> chars;
        for (int i = 0; i < n; ++i) {
            if (S[i] != '-')
                chars.push_back(toupper(S[i]));
        }
        return string(chars.begin(), chars.end());
    }

public:
    string licenseKeyFormatting(string S, int K) {
        S = removeDash(S);
        int n = S.length();
        if (n <= K)
            return S;
        vector<char> chars;
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            chars.push_back(S[i]);
            count++;
            if (count == K) {
                chars.push_back('-');
                count = 0;
            }
        }
        if (chars.back() == '-')
            chars.pop_back();
        return string(chars.rbegin(), chars.rend());
    }
};