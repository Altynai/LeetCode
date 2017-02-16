class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int k = 2; k < n; ++k) {
            int compared = target - nums[k];
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] < compared) {
                    ans += j - i;
                    i++;
                } else
                    j--;
            }
        }
        return ans;
    }
};