class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size() - 1, m = num2.size() - 1;
        int base = 0, length = max(num1.size(), num2.size());
        string ans(length, '0');
        int index = length - 1;
        while (n >= 0 || m >= 0) {
            int a = n >= 0 ? num1[n] - '0' : 0;
            int b = m >= 0 ? num2[m] - '0' : 0;
            int s = a + b + base;
            if (s < 10) {
                ans[index] = '0' + s;
                base = 0;
            } else {
                ans[index] = '0' + s - 10;
                base = 1;
            }
            index--;
            n--;
            m--;
        }
        if (base)
            ans = "1" + ans;
        return ans;
    }
};