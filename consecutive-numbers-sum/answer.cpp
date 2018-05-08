class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ans = 0;
        int threshold = (int)sqrt((double)N * 2);
        for (int i = 1; i <= threshold; i++) {
            // odd
            if (i % 2 == 1) {
                if (N % i != 0)
                    continue;
                int average = N / i;
                if (average < (i + 1) / 2)
                    continue;
            } else {
                int pairs = i / 2;
                if (N % pairs != 0)
                    continue;
                int sum = N / pairs;
                if (sum % 2 == 0)
                    continue;
                int small = (sum - 1) / 2;
                if (small < pairs)
                    continue;
            }
            ans++;
        }
        return ans;
    }
};