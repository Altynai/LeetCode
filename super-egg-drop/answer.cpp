#define A 500
#define B 101
int dp[A][B];

class Solution {
public:
    int superEggDrop(int K, int N) {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; ;i++) {
            for (int j = 1; j <= K; j++) {
                dp[i][j] = 1 + dp[i - 1][j - 1] + dp[i - 1][j];
                if (dp[i][j] >= N)
                    return i;
            }
        }
        return N;
    }
};
