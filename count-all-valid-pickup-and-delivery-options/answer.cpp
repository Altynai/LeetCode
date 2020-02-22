#define int64 long long

class Solution {
public:
    int countOrders(int n) {
        vector<int64> dp(n + 1, 0);
        dp[1] = 1;
        int64 mod = 1000000000 + 7;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] * (2 * i * i - i) % mod;
        return dp[n];
    }
};
