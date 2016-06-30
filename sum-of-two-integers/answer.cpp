class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int diff = a ^ b;
            int common = a & b;
            a = diff;
            b = common << 1;
        }
        return a;
    }
};