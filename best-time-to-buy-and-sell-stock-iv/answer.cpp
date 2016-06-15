
#define NIL -999999999

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; ++i)
                profit += max(prices[i] - prices[i - 1], 0);
            return profit;
        }
        vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
        for (int j = 1; j <= k; ++j) {
            int value = NIL;
            for (int i = 1; i <= n; ++i) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                if (value != NIL)
                    dp[i][j] = max(dp[i][j], value + prices[i - 1]);
                if (value == NIL || dp[i][j - 1] - prices[i - 1] > value)
                    value = dp[i][j - 1] - prices[i - 1];
            }
        }
        return dp[n][k];
    }
};