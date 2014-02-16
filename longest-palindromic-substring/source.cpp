#include "string"
#include "cstdio"
#include "iostream"
using namespace std;

class Solution {
private:
    void addSpecialChar(char ch[], const string &s) {
        int length = s.size(), index = 0;
        ch[index++] = '$';
        for (int i = 0; i < length; i++) {
            ch[index++] = '#';
            ch[index++] = s[i];
        }
        ch[index++] = '#';
        ch[index++] = '\0';
    }

    string deleteSpecialChar(char ch[], int id, int expend) {
        string s = "";
        for (int i = id - expend + 1; i < id + expend; i++) {
            if (ch[i] != '#')
                s += ch[i];
        }
        return s;
    }

    string manacher(const string &s) {
        int length = s.size();
        int n = length * 2 + 3;
        char *ch = new char[n];
        int *expend = new int[n];

        addSpecialChar(ch, s);
        int id = 0, mx = 1; // id: center of current longest palindrome
        for (int i = 1; i < n; i++) {
            expend[i] = mx > i ? min(expend[2 * id - i], mx - i) : 1;
            while (ch[i + expend[i]] == ch[i - expend[i]]) {
                expend[i]++;
            }
            if (i + expend[i] > mx) {
                mx = i + expend[i];
                id = i;
            }
        }
        int index = 1;
        for (int i = 2; i < n; i++) {
            if (expend[i] > expend[index])
                index = i;
        }
        return deleteSpecialChar(ch, index, expend[index]);
    }

public:
    string longestPalindrome(string s) {
        return manacher(s);
    }
};

int main(int argc, char const *argv[]) {
    Solution *solution = new Solution();
    cout << (solution->longestPalindrome("vommleztyrbrnoij")) << endl;
    return 0;
}