#define N 10
#define NIL -1
#define M 1 << N

class Solution {
private:
    int bitCount(int mask) {
        int count = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i))
                count++;
        }
        return count;
    }

public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n >= 10)
            n = 10;
        vector<vector<int> > dp = vector<vector<int> >(n + 1, vector<int>(M, NIL));
        for (int bit = 1; bit < N; ++bit)
            dp[1][1 << bit] = 1;
        for (int i = 1; i < n; ++i) {
            for (int mask = 0; mask < M; mask++) {
                if (dp[i][mask] == NIL)
                    continue;
                for (int bit = 1; bit < N; ++bit) {
                    if (mask & (1 << bit))
                        continue;
                    int& value = dp[i + 1][mask | (1 << bit)];
                    if (value == NIL)
                        value = 0;
                    value += dp[i][mask];
                }
            }
        }
        int sum = 1;
        for (int i = 1; i <= n; ++i) {
            for (int mask = 0; mask < M; mask++) {
                int count = bitCount(mask);
                if (dp[i][mask] != NIL) {
                    sum += dp[i][mask];
                    if (count + 1 <= n)
                        sum += dp[i][mask] * count;
                }
            }
        }
        return sum;
    }
};