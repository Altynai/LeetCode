
class Solution {
public:
    string countAndSay(int n) {
        if (n == 0)
            return string("");
        int m = n * n * n; // interesting number
        int **digits = new int *[2];
        for (int i = 0; i < 2; i++)
            digits[i] = new int[m];
        int current = 0, dn[2] = {0, 0};
        // init when n = 1
        digits[current][dn[current]++] = 1;
        for (int i = 2, count = 1; i <= n; i++) {
            dn[current ^ 1] = 0;
            count = 1;
            for (int j = 1; j < dn[current]; j++) {
                if (digits[current][j] == digits[current][j - 1])
                    count++;
                else {
                    digits[current ^ 1][dn[current ^ 1]++] = count;
                    digits[current ^ 1][dn[current ^ 1]++] = digits[current][j - 1];
                    count = 1;
                }
            }
            // add the last
            digits[current ^ 1][dn[current ^ 1]++] = count;
            digits[current ^ 1][dn[current ^ 1]++] = digits[current][dn[current] - 1];
            current ^= 1;
        }
        string result = string(dn[current], '0');
        for (int i = 0; i < dn[current]; i++)
            result[i] += digits[current][i];
        return result;
    }
};