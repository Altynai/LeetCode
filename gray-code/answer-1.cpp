
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        if (n == 0)
            return result;
        int value = 0, bit = 0, delta = 1;
        for (int i = 0; i < (1 << n) - 1; i++) {
            value ^= (1 << bit);
            result.push_back(value);
            if (bit == n - 1) {
                bit = n - 2;
                delta = -1;
            } else if (bit == 0) {
                bit = 1;
                delta = 1;
            } else
                bit += delta;
        }
        return result;
    }
};