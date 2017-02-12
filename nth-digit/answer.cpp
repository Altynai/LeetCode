class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10)
            return n;
        long long m = n;
        long long tens = 10, base = 9, total = 9;
        int length = 2;
        while (m > total + base * 10 * length) {
            total += base * 10 * length;
            base *= 10; // 9 -> 90 -> 900 -> 9000
            length++;
            tens *= 10;
        }
        m -= total;
        long long number = tens;
        char *buff = new char[length + 1];
        if (m % length == 0) {
            number += m / length - 1;
            sprintf(buff, "%lld", number);
            return (int)(buff[length - 1] - '0');
        } else {
            number += m / length;
            int offset = m % length - 1;
            sprintf(buff, "%lld", number);
            return (int)(buff[offset] - '0');
        }
    }
};