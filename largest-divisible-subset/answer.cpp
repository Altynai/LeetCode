class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret;
        if (n == 0)
            return ret;
        sort(nums.begin(), nums.end());
        vector<int> pre(n);
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i)
            pre[i] = i;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (nums[j] % nums[i] == 0) {
                    if (dp[j] < dp[i] + 1) {
                        dp[j] = dp[i] + 1;
                        pre[j] = i;
                    }
                }
            }
        }
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > dp[index])
                index = i;
        }
        while (index != pre[index]) {
            ret.push_back(nums[index]);
            index = pre[index];            
        }
        ret.push_back(nums[index]);
        return ret;
    }
};