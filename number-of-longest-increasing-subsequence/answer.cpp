#define N 2001
int dp[N][N];

class Solution {
private:
    int longest, n;
    vector<int> nums;

    void init(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
    }

    void findLongest() {
        longest = 1;
        for (int i = 0; i < n; i++)
            dp[0][i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[0][i] = max(dp[0][i], dp[0][j] + 1);
                    longest = max(dp[0][i], longest);
                }
            }
        }
    }

    int solve() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n; j++) {
                if (j <= i + 1)
                    dp[i][j] = -1;
                else
                    dp[i][j] = 0;
            }
            dp[i][1] = 1;
        }
        int sum = 0;
        for (int i = longest - 1; i < n; i++)
            sum += dfs(i, longest);
        return sum;
    }

    int dfs(int j, int k) {
        if (dp[j][k] != -1)
            return dp[j][k];
        dp[j][k] = 0;
        for (int i = 0; i < j; i++) {
            if (nums[i] < nums[j])
                dp[j][k] += dfs(i, k - 1);
        }
        return dp[j][k];
    }

public:
    int findNumberOfLIS(vector<int>& nums) {
        init(nums);
        if (n == 0)
            return 0;
        findLongest();
        return solve();
    }
};