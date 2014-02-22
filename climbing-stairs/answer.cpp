
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0)
            return 0;
        int *dp = new int[n + 1];
        memset(dp, 0 , sizeof(int) * (n + 1));
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            dp[i + 1] += dp[i];
            if (i + 2 <= n)
                dp[i + 2] += dp[i];
        }
        return dp[n];
    }
};