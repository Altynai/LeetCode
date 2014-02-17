
class Solution {
private:
    static const int MAX_INT = 0x7fffffff;
    static const int MIN_INT = -0x7fffffff - 1;

    int convert(const char *str, bool negative) {
        long long result = 0;
        while (*str != '\0') {
            if (*str < '0' || *str > '9')
                break;
            result = result * 10 + (*str - '0');
            str++;
        }
        if (negative)
            result = -result;
        if (result > MAX_INT)
            return MAX_INT;
        if (result < MIN_INT)
            return MIN_INT;
        return (int)result;
    }

public:
    int atoi(const char *str) {
        if (str == NULL || *str == '\0')
            return 0;
        while (*str == ' ')
            str++;
        if (*str == '-')
            return convert(str + 1, true);
        else if (*str == '+')
            return convert(str + 1, false);
        else
            return convert(str, false);
    }
};