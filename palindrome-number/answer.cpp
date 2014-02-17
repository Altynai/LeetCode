
class Solution {
private:
    int length(int x) {
        int result = 1;
        while (x > 9) {
            result++;
            x /= 10;
        }
        return result;
    }

    int digitAt(int x, int i, int tens[]) {
        return (x / tens[i]) % 10;
    }

public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int tens[10] = {1};
        for (int i = 1; i < 10; i++)
            tens[i] = tens[i - 1] * 10;
        int len = length(x);
        for (int i = 0; i < len; i++) {
            if (digitAt(x, i, tens) != digitAt(x, len - i - 1, tens))
                return false;
        }
        return true;
    }
};
