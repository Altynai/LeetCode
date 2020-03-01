class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> copyed(nums.begin(), nums.end());
        sort(copyed.begin(), copyed.end());
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
            ans[i] = lower_bound(copyed.begin(), copyed.end(), nums[i]) - copyed.begin();
        return ans;
    }
};
