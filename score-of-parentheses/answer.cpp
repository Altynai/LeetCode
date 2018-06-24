#define LP -1
#define RP -2

class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<int> chs;
        int m = S.size();
        for (int i = 0; i < m; i++) {
            if (S[i] == '(')
                chs.push_back(LP);
            else {
                int n = chs.size();
                // ()
                if (chs[n - 1] == LP)
                    chs[n - 1] = 1;
                // (X) -> 2X
                else if (n >= 2 && chs[n - 2] == LP) {
                    int num = chs.back() * 2;
                    chs.pop_back();
                    chs.pop_back(); // LP
                    chs.push_back(num);
                }
                while (chs.size() >= 2 && chs[chs.size() - 1] > 0 && chs[chs.size() -2 ] > 0) {
                    int num1 = chs.back();
                    chs.pop_back();
                    int num2 = chs.back();
                    chs.pop_back();
                    chs.push_back(num1 + num2);
                }
            }
        }
        return accumulate(chs.begin(), chs.end(), 0);
    }
};
