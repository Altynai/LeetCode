class Solution {
public:
    bool divisorGame(int N) {
        bool dp[N + 1];
        dp[1] = false;
        for (int j = 2; j <= N; j++) {
            dp[j] = false;
            for (int i = 1; i < j; i++) {
                if (j % i == 0 && dp[j - i] == false) {
                    dp[j] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
