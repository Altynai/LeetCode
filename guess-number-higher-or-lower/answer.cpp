// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
#define i64 long long

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        i64 low = 1, high = n, mid = 1;
        while (low <= high) {
            mid = (low + high) >> 1;
            int flag = guess(mid);
            if (flag == 0)
                return mid;
            else if (flag < 0)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return 0;
    }
};