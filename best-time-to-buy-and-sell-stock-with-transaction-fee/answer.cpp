#define N 50001
int dp[N];

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1)
            return 0;

        for (int i = 0; i <= n; i++)
            dp[i] = 0;
        int best = 0, cache = -prices[0];
        for (int i = 1; i <= n; i++) {
            int pi = prices[i - 1];
            // skip
            dp[i] = dp[i - 1];
            // pick
            dp[i] = max(dp[i], cache + pi - fee);
            best = max(best, dp[i]);
            cache = max(cache, dp[i - 1] - pi);
        }
        return best;
    }
};