
class Solution {
private:
    static const int MIN_INT = -0x7fffffff - 1;
    static const int MAX_SUM = 1073741824;

    long long abs(long long x) {
        return x > 0 ? x : -x;
    }

public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor)
        	return 1;
        if (divisor == MIN_INT)
            return 0;
        bool nagtive = false;
        if (dividend < 0 && divisor > 0)
            nagtive = true;
        if (dividend > 0 && divisor < 0)
            nagtive = true;
        long long _dividend = abs(dividend);
        long long _divisor = abs(divisor);
        long long count = 1LL, sum = _divisor;
        int result = 0;
        while (_dividend >= _divisor) {
            if (_divisor >= MAX_SUM) {
                result++;
                _dividend -= _divisor;
            }
            count = 1;
            sum = _divisor;
            while (_dividend >= sum && sum < MAX_SUM) {
                _dividend -= sum;
                result += count;
                count += count;
                sum += sum;
            }
        }
        return nagtive ? -result : result;
    }
};
