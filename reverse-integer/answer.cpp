
class Solution {
public:
    int reverse(int x) {
        return x > 0 ? reversePositive(x) : -reversePositive(-x);
    }

private:
    static const int MAX_INT = 0x7fffffff;
    int reversePositive(int x) {
        int result = 0;
        while (x > 0) {
            result = result * 10 + x % 10;
            x /= 10;
            if (result < 0) // overflow
                return 0;
        }
        return result;
    }
};