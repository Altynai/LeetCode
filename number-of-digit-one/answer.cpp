class Solution {
private:
    int pow(int x, int y) {
        int answer = 1;
        for (int i = 0; i < y; ++i)
            answer *= x;
        return answer;
    }

    int pick(int n, int m) {
        int answer = 1;
        for (int i = n; i >= n - m + 1; i--)
            answer *= i;
        for (int i = 2; i <= m; ++i)
            answer /= i;
        return answer;
    }

public:
    int countDigitOne(int n) {
        if (n <= 0)
            return 0;
        char buffer [15];
        sprintf(buffer, "%d", n);
        int len = strlen(buffer);

        int answer = 0, count = 0;
        for (int i = 0; i < len; ++i) {
            int digit = buffer[i] - '0';
            if (digit == 0)
                continue;
            else {
                // pick non one
                int remain = len - 1 - i;
                for (int j = 0; j < digit; j++) {
                    int extra = j == 1 ? 1 : 0;
                    for (int k = 0; k <= remain ; ++k)
                        answer += pick(remain, k) * pow(9, remain - k) * (k + count + extra);
                }
            }
            if (digit == 1)
                count++;
        }
        answer += count;
        return answer;
    }
};