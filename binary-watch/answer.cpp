class Solution {
public:
    int countBits(int n) {
        int count = 0;
        while (n >= 1) {
            if (n % 2 == 1)
                count++;
            n >>= 1;
        }
        return count;
    }

    string format(int top, int bottom) {
        char buff[20];
        sprintf(buff, "%d:%02d", top, bottom);
        return string(buff);
    }

    vector<string> readBinaryWatch(int num) {
        int n = min(num, 10);
        vector<string> times;
        for (int top = 0; top < 12; top++) {
            for (int bottom = 0; bottom < 60; ++bottom) {
                if (countBits(top) + countBits(bottom) != n)
                    continue;
                times.push_back(format(top, bottom));
            }
        }
        return times;
    }
};