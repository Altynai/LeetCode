class Solution {
public:
    int bulbSwitch(int n) {
        if (n == 0)
            return 0;
        int i = 1, times = 3, sum = 0;
        while (sum + times < n) {
            sum += times;
            times += 2;
            i++;
        }
        return i;
    }
};