class Solution {
public:
    int addDigits(int num) {
        if (num < 10)
            return num;
        int sum = 0;
        while (num >= 1) {
            sum += num % 10;
            num /= 10;
        }
        return this->addDigits(sum);
    }
};
