class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        int answer = 0;
        vector<int> dp(n, 0);
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < j; ++i) {
                if (prices[i] >= prices[j])
                    continue;
                int profit = prices[j] - prices[i];
                if (i - 2 >= 0)
                    dp[j] = max(dp[j], dp[i - 2] + profit);
                else
                    dp[j] = max(dp[j], profit);
            }
            if (j > 0)
                dp[j] = max(dp[j], dp[j - 1]);
            answer = max(answer, dp[j]);
        }
        return answer;
    }
};