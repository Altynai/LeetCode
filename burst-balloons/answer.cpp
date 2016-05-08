#include <vector>

using namespace std;

class Solution {
private:
    int n;
    vector<vector<int> > dp;
    vector<int> nums;

    void init(vector<int>& nums) {
        n = nums.size();
        if (n == 0)
            return;
        dp = vector<vector<int> >(n);
        for (int i = 0; i < n; ++i) {
            dp[i] = vector<int>(n, 0);
            int coin = nums[i];
            if (i > 0)
                coin *= nums[i - 1];
            if (i + 1 < n)
                coin *= nums[i + 1];
            dp[i][i] = coin;
        }
        this->nums = nums;
    }

    int solve() {
        if (n == 0)
            return 0;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = i; k <= j; ++k) {
                    // burst balloon i, (i + 1, j) -> (i, j)
                    int coin = nums[k];
                    coin *= (i > 0 ? nums[i - 1] : 1);
                    coin *= (j + 1 < n ? nums[j + 1] : 1);
                    int base = 0;
                    base += (k > i ? dp[i][k - 1] : 0);
                    base += (k < j ? dp[k + 1][j] : 0);
                    dp[i][j] = std::max(dp[i][j], base + coin);
                }
            }
        }
        return dp[0][n - 1];
    }

public:
    int maxCoins(vector<int>& nums) {
        init(nums);
        return solve();
    }
};