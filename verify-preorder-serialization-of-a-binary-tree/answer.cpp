#include <vector>
#include <string>
using namespace std;

const int SHARP = -1;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int comma = 0, n = preorder.size();
        for (int i = 0; i < n; ++i) {
            if (preorder[i] == ',')
                comma++;
        }
        if (n == 0 || comma % 2 == 1)
            return false;
        vector<int> stk;
        int i = 0, top = 0;
        while (i < n) {
            int pasre = 0;
            while (i < n && preorder[i] != ',') {
                if (preorder[i] == '#') {
                    pasre = SHARP;
                    i++;
                    break;
                } else {
                    pasre = pasre * 10 + preorder[i] - '0';
                    i++;
                }
            }
            i++;
            if (top == stk.size())
                stk.push_back(pasre);
            else
                stk[top] = pasre;
            top++;
            while (top >= 3 && stk[top - 1] == SHARP && stk[top - 2] == SHARP && stk[top - 3] != SHARP) {
                top -= 2;
                stk[top - 1] = SHARP;
            }
        }
        return top == 1 && stk[0] == SHARP;
    }
};