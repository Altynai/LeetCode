class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int best = 1, len = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1])
                best = max(best, ++len);
            else
                len = 1;
        }
        return best;
    }
};