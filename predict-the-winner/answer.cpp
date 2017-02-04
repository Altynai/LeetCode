#define N 21

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> total = vector<int>(n);
        total[0] = nums[0];
        for (int i = 1; i < n; ++i)
            total[i] = total[i - 1] + nums[i];
        int dp[N][N];
        for (int i = 0; i < n; ++i)
            dp[i][i] = nums[i];
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int s = (i == 0) ? total[j] : total[j] - total[i - 1];
                dp[i][j] = s - std::min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= (total[n - 1] + 1) / 2;
    }
};
