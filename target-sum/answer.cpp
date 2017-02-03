#define BASE 1000
#define N 1000 * 2 + 1

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ways = 0, n = nums.size();
        if (n == 0)
            return 0;
        vector<vector<int> > dp(n, vector<int>(N));
        int first = nums[0];
        dp[0][BASE + first] += 1;
        dp[0][BASE - first] += 1;
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            for (int j = 0; j < N; ++j) {
                if (dp[i - 1][j] == 0)
                    continue;
                dp[i][j + num] += dp[i - 1][j];
                dp[i][j - num] += dp[i - 1][j];
            }
        }
        if (S > BASE)
            return 0;
        return dp[n - 1][BASE + S];
    }
};