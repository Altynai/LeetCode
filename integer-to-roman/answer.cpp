
class Solution {
private:
    static const int N;
    static const int integers[];
    static const string strings[];

public:
    string intToRoman(int num) {
        string result = "";
        for (int i = N - 1; num && i >= 0; i--) {
            while (num && num >= integers[i]) {
                num -= integers[i];
                result += strings[i];
            }
        }
        return result;
    }
};

const int Solution::N = 13;
const int Solution::integers[] = {
    1, 4, 5, 9, 10,
    40, 50, 90, 100, 400,
    500, 900, 1000
};
const string Solution::strings[] = {
    "I", "IV", "V", "IX", "X",
    "XL", "L", "XC", "C", "CD",
    "D", "CM", "M"
};