class Solution {
public:
    bool isPerfectSquare(int num) {
        for (int i = 1; i * i >= 0 && i * i <= num; ++i) {
            if (i * i == num)
                return true;
        }
        return false;
    }
};